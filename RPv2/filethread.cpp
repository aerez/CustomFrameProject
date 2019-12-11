#include "filethread.hpp"

int Filethread::fileCount;

Filethread::Filethread(QObject *parent, int sockfd, struct addrinfo *p, std::string filepath,std::string filename)
    :QThread(parent){
    this->sockfd=sockfd;
    this->p=p;
    this->filepath=filepath;
    this->filename=filename;
    fileCount++;
}

void Filethread::run(){
    qDebug()<<"running\n";

    FILE* f;
    QMutex mutex;
    int numbytes;
    struct in_addr loopback;
    inet_pton(AF_INET,p->ai_addr->sa_data,&loopback);


            //string name=path;
            //name.append(names[i]);
            f = fopen(filepath.c_str(), "rb");
            if (f == NULL) {
                qDebug()<< "fileopen error" << endl;
                //return 1;
            }

            fseek(f, 0, SEEK_END);
            long double sz = ftell(f);
            fseek(f, 0, SEEK_SET);
            sz = ceil(sz / MAXDATALEN);
            uint16_t x = 1;
            qDebug()<<QString::fromUtf8(filename.c_str())<<"\n";
            qDebug()<<"filesize: "<<filename.size()<<"\n";
            int n=filename.size();
            char name[n];

            strcpy(name, filename.c_str());

            infopacket info(filename.size(),name,fileCount,(uint16_t)sz);

            std::string packet= info.serialize_frame();
            for(int i=0;i<filename.size();i++){
                qDebug()<<(char)packet[i+6];
            }


            sendto(sockfd, packet.c_str(), packet.size(), 0, p->ai_addr, p->ai_addrlen);
            emit ConsoleChanged("SENDING: "+QString::fromUtf8(filepath.c_str())+"\n");
            emit ConsoleChanged("NUMBER OF CHUNKS: " + QString::number((int)sz) +"\n");

            while (x <= sz) {
                mutex.lock();
                char databuffer[MAXDATALEN];
                numbytes = fread(databuffer, 1, MAXDATALEN, f);
                DataPacket cf(numbytes,databuffer,1,loopback.s_addr,loopback.s_addr,x);

                QString chunkmsg="Sent( "+QString::number(x)+"/"+ QString::number((int)sz)+")";
                emit ConsoleChanged(chunkmsg);
                std::string frame= cf.serialize_frame();
                if (numbytes > 0) {
                    sendto(sockfd, frame.c_str(), frame.size(), 0, p->ai_addr, p->ai_addrlen);
                    emit progressChanged(x,sz);
                    x++;

                }
                if (numbytes < MAXDATALEN+14) {
                    if (feof(f)) {
                        emit ConsoleChanged("FINISHED !\n");

                    }
                    if (ferror(f))
                        qDebug() << "Error reading" << endl;


                }

                mutex.unlock();





            this->msleep(500);

           }
}




