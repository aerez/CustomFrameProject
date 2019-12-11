#ifndef FILETHREAD_HPP
#define FILETHREAD_HPP

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

#include "Packets/datapacket.hpp"
#include "Packets/infopacket.hpp"


class Filethread : public QThread
{
    Q_OBJECT
public:
    explicit Filethread(QObject *parent = nullptr,int sockfd=0, struct addrinfo *p=nullptr,std::string filepath="",std::string filename="");
    void run() override;
    int sockfd;
    static int fileCount;
    struct addrinfo *p;
    std::string filepath,filename;

signals:
    void ConsoleChanged(QString);

    void progressChanged(int,int);

public slots:
};

#endif // FILETHREAD_HPP
