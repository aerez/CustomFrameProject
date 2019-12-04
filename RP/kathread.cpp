#include "kathread.hpp"

KAThread::KAThread(QObject *parent,int sockfd, struct addrinfo *p) : QThread(parent){
    this->sockfd=sockfd;
    this->p=p;
}

void KAThread::run(){
    KAPacket ka;
    QMutex mutex;
    std::string msg= ka.serialize_frame();
    while(!stop){
        mutex.lock();
        sendto(sockfd, msg.c_str(),msg.size(),0,p->ai_addr,p->ai_addrlen);
        emit ConsoleChanged("Sent Keep Alive");
        qDebug()<<"Sent keep Alive\n";
        mutex.unlock();

        this->msleep(3000);
    }

}
