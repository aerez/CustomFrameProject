#include "receiverwindow.hpp"
#include "ui_receiverwindow.h"

ReceiverWindow::ReceiverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReceiverWindow)
{
    ui->setupUi(this);
    QString sPath ="/home/aerez/";

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView->setModel(dirmodel);
    setConfig();
    ui->textBrowser_3->setText(QString::fromUtf8(ip.c_str()));
    ui->textBrowser_4->setText(QString::fromUtf8(port.c_str()));

    ui->progressBar->setValue(0);


    ui->console->append("hi\n");

    setUpSocket();






}

ReceiverWindow::~ReceiverWindow()
{
    delete ui;
}

void ReceiverWindow::onConsoleChanged(QString txt){
    ui->console->append(txt);
}

int ReceiverWindow::setUpSocket(){
    int sockfd;
        struct addrinfo hints,*servinfo,*p;
        int rv;




        memset(&hints,0,sizeof hints);
        hints.ai_family=AF_INET;
        hints.ai_socktype=SOCK_DGRAM;




        if((rv=getaddrinfo(ip.c_str(),port.c_str(),&hints,&servinfo))!=0){
            qDebug()<<"getadddrinfo "<<gai_strerror(rv)<<endl;
            return 1;
        }
        for(p=servinfo;p!=NULL;p=p->ai_next){
            if((sockfd= socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
                perror("listerner:socket");
                continue;
            }

            if(bind(sockfd,p->ai_addr,p->ai_addrlen)==-1){
                perror("listener: bind");
                continue;
            }
            break;
        }

        if(p==NULL){
            qDebug()<<"listener failed to bind socket"<<endl;
            return 2;
        }
        freeaddrinfo(servinfo);

        this->sockfd=sockfd;
        this->p=p;

}

void ReceiverWindow::setConfig(){
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

void ReceiverWindow::on_treeView_clicked(const QModelIndex &index)
{
    dirpath=dirmodel->fileInfo(index).absoluteFilePath().toUtf8().constData();
    ui->textBrowser_5->setText("Path: "+ QString::fromUtf8(dirpath.c_str()));
}

void ReceiverWindow::on_pushButton_clicked()
{
    fm= new FileManager(this,dirpath,sockfd);
    QObject::connect(fm, SIGNAL(ConsoleChanged(QString)),this, SLOT(onConsoleChanged(QString)));
    QObject::connect(fm,SIGNAL(progressChanged(int,int)),this,SLOT(on_progressBar_valueChanged(int,int)));

    fm->start();
}

void ReceiverWindow::on_progressBar_valueChanged(int value,int max)
{
    ui->progressBar->setRange(0,max);
    ui->progressBar->setValue(value);
}



//std::vector<FileWriter>::iterator ReceiverWindow::getFileByFileID(int fileID){
//    std::vector<FileWriter>::iterator p;
//    for( p=files.begin();p<files.end();p++){
//        if(p->getFileID()==fileID)
//            return p;
//    }
//    return p;

//}


