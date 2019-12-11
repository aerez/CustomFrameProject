#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <QObject>
#include <QThread>
#include <QMutex>

#include "filewriter.hpp"
#include "Packets/datapacket.hpp"
#include "Packets/infopacket.hpp"
#include "Packets/infopacket.hpp"

class FileManager : public QThread
{
    Q_OBJECT

    std::vector<FileWriter> files;
    int sockfd;
    std::string dir;
    bool running;

public:
    FileManager(QObject *parent=0,std::string="",int sockfd=0);

    void run() override;


signals:
    void ConsoleChanged(QString);

    void progressChanged(int,int);

};

#endif // FILEMANAGER_HPP
