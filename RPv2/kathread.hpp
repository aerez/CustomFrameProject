#ifndef KATHREAD_HPP
#define KATHREAD_HPP

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "Packets/kapacket.hpp"

class KAThread : public QThread
{
    Q_OBJECT
public:
    explicit KAThread(QObject *parent = 0,int sockfd=0,struct addrinfo *p=nullptr);
    void run();
    bool stop;
    int sockfd;
    struct addrinfo *p;
signals:
    void ConsoleChanged(QString);


};

#endif // KATHREAD_HPP
