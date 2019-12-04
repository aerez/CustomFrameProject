#include "senderwindow.hpp"
#include "ui_senderwindow.h"




SenderWindow::SenderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SenderWindow)
{
    ui->setupUi(this);
    setConfig();
    QString q= QString::fromUtf8(ip.c_str());
    ui->textBrowser_2->setText(q);
    q= QString::fromUtf8(port.c_str());
    ui->textBrowser_3->setText(q);

    QString sPath ="/home";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView->setModel(dirmodel);

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);
    ui->listView->setModel(filemodel);



}

SenderWindow::~SenderWindow()
{
    delete ui;
}



void SenderWindow::setConfig(){
    std::ifstream file("/home/aerez/Desktop/config.txt");
       std::string line;

       if(file.is_open()){
           while(getline(file,line)){
               std::istringstream is_line(line);
               std::string key;
               if(getline(is_line,key,'='))
               {
                   std::string value;
                   if(getline(is_line,value)){
                       if(key=="ip")
                           ip=value;
                       if(key=="port")
                           port=value;
                   }
               }


           }
           file.close();

       }
       else qDebug()<<"Unable to open file";
}

int SenderWindow::establishConnection(){
    int sockfd=0;
    struct addrinfo hints, *servinfo,*p;
    int rv;
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;

    if((rv=getaddrinfo(ip.c_str(),port.c_str(),&hints,&servinfo))!=0){
        qDebug()<<"error getaddrinfo "<<gai_strerror(rv)<<endl;
        return 1;
    }

    for(p=servinfo;p!=nullptr;p=p->ai_next){
        if((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
            perror("socket");
            continue;
        }
        break;
    }
    if(p==nullptr){
        qDebug()<<"error creating socket"<<endl;
        return 2;
    }



    this->sockfd=sockfd;
    this->p=p;
    kathread= new KAThread(this,sockfd,p);
    QObject::connect(kathread,SIGNAL(ConsoleChanged(QString)),this, SLOT(onConsoleChanged(QString)));

    kathread->start();





    return 1;
}

int SenderWindow::sendFile(std::string filename){
    FILE* f;
        int numbytes;
        //string names[]={"wireshark.jpg","team-rocket-2.png","onemb.jpg","test100k.db","file5.zip"};
        int counter=5;
        struct in_addr loopback;
        inet_pton(AF_INET,ip.c_str(),&loopback);

        for(int i=0;i<1;i++) {
            //string name=path;
            //name.append(names[i]);
            f = fopen(filename.c_str(), "rb");
            if (f == NULL) {
                qDebug()<< "fileopen error" << endl;
                return 1;
            }

            fseek(f, 0, SEEK_END);
            long double sz = ftell(f);
            fseek(f, 0, SEEK_SET);
            sz = ceil(sz / MAXDATALEN);
            uint16_t x = 1;

            ui->consoleText->append("SENDING: "+QString::fromUtf8(filename.c_str())+"\n");
            ui->consoleText->append("NUMBER OF CHUNKS: " + QString::number((int)sz) +"\n");
            sendto(sockfd, &sz, sizeof(sz), 0, p->ai_addr, p->ai_addrlen);

            while (x <= sz) {
                char databuffer[MAXDATALEN];
                numbytes = fread(databuffer, 1, MAXDATALEN, f);
                DataPacket cf(numbytes,databuffer,i,loopback.s_addr,loopback.s_addr,x);
                ui->consoleText->append("\r");
                QString chunkmsg="Sent( "+QString::number(x)+"/"+ QString::number((int)sz)+")";
                ui->consoleText->append(chunkmsg);
                std::string frame= cf.serialize_frame();
                if (numbytes > 0) {
                    sendto(sockfd, frame.c_str(), frame.size(), 0, p->ai_addr, p->ai_addrlen);
                    x++;

                }
                if (numbytes < MAXDATALEN+14) {
                    if (feof(f)) {
                        qDebug()<<"COMPLETED" << endl ;

                    }
                    if (ferror(f))
                        qDebug() << "Error reading" << endl;


                }





            std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            }

        }
}




void SenderWindow::on_btnStart_clicked()
{
    this->establishConnection();
}

void SenderWindow::onConsoleChanged(QString msg){
    ui->consoleText->append(msg);
}

void SenderWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath= dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void SenderWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QString p;
    p=dirmodel->fileInfo(index).absoluteFilePath();
    path= p.toUtf8().constData();
    ui->btnSend->setText("Send File: "+filemodel->fileInfo(index).fileName());
}

void SenderWindow::on_btnSend_clicked()
{
    qDebug()<<"clicked\n";
    filethread = new Filethread(this, sockfd,p,path);
    QObject::connect(filethread,SIGNAL(progressChanged(int,int)),this,SLOT(on_progressBar_valueChanged(int,int)));
    QObject::connect(filethread, SIGNAL(ConsoleChanged(QString)),this,SLOT(onConsoleChanged(QString)));
    filethread->start();
}

void SenderWindow::on_progressBar_valueChanged(int value,int max)
{
    ui->progressBar->setRange(0,max);
    ui->progressBar->setValue(value);
}
