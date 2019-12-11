#include "senderwindow.hpp"
#include "ui_senderwindow.h"



static std::string filename,filepath;


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

    ui->progressBar->setValue(0);



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
    filepath= p.toUtf8().constData();
    filename=filemodel->fileInfo(index).fileName().toUtf8().constData();
    ui->btnSend->setText("Send File: "+filemodel->fileInfo(index).fileName());
}

void SenderWindow::on_btnSend_clicked()
{
    qDebug()<<"clicked\n";
    filethread = new Filethread(this, sockfd,p,filepath,filename);
    QObject::connect(filethread,SIGNAL(progressChanged(int,int)),this,SLOT(on_progressBar_valueChanged(int,int)));
    QObject::connect(filethread, SIGNAL(ConsoleChanged(QString)),this,SLOT(onConsoleChanged(QString)));
    filethread->start();
}

void SenderWindow::on_progressBar_valueChanged(int value,int max)
{
    ui->progressBar->setRange(0,max);
    ui->progressBar->setValue(value);
}
