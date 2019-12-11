#include "filemanager.hpp"

FileManager::FileManager(QObject *parent,std::string dir,int sockfd):QThread(parent)
{
    running=true;
    this->sockfd=sockfd;
    this->dir=dir;
}

void FileManager::run(){
    int chunkcount=1;
    QMutex m;
    FILE *f;
    int byteReceieved;
    struct sockaddr_storage their_addr;
    socklen_t addr_len;
    infopacket *ipack;


    while(running){

        //qDebug()<<"hello";
        char buffer[MAXDATALEN+14]={0};

        m.lock();
        byteReceieved= recvfrom(sockfd,buffer,MAXDATALEN+14,0,(struct sockaddr*)&their_addr,&addr_len);
        //qDebug()<<(int)buffer[0]<<"\n";
        switch (buffer[0]) {
            case KeepAlive:{
                emit ConsoleChanged("RECEIVED KEEP ALIVE");
            break;
        }

            case Info:{
            ipack=new infopacket(buffer);
            emit ConsoleChanged("RECEIVED INFO-> file name: "+ QString::fromUtf8(ipack->getData()) +
                                " chunks: "+QString::number(ipack->getchunks()));
            std::string fi=dir;
            fi.append("/");
            fi.append(ipack->getData());
            f=fopen(fi.c_str(),"wb");
            if(f==NULL){
                emit ConsoleChanged("Error opening file");
            }
            break;
        }

            case Data: {
            DataPacket dpack(buffer);
            fseek(f,MAXDATALEN*(dpack.getChunkId()-1),SEEK_SET);
            fwrite(dpack.getData(),1,dpack.getDatalen(),f);
            emit ConsoleChanged("received: ("+QString::number(chunkcount++)+"/"+QString::number(ipack->getchunks())+")");
            emit progressChanged(chunkcount,ipack->getchunks());
            if(chunkcount>ipack->getchunks()){
                fclose(f);
            }


            break;
        }

        }
        m.unlock();
}
}
