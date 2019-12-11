#ifndef FILEWRITER_HPP
#define FILEWRITER_HPP

#include <QObject>

#include <QDebug>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "Packets/basicpacket.hpp"

class FileWriter: public QObject
{
    Q_OBJECT

    int fileID,chunks;
    int counter=0;

    std::string dirpath,filename;
    FILE* f;
public:
    FileWriter(QObject *parent,std::string dirpath,std::string filename,int fileID, int chunks);
    ~FileWriter();
    void writeChunk(int chunkID,const char* data,int datasize);

    int getFileID();



signals:
    void ConsoleChanged(QString);

};

#endif // FILEWRITER_HPP
