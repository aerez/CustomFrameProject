//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include <cmath>
#include "FileSender.h"


using namespace std;

FileSender::FileSender(char *path) : path(path){};



int FileSender::Run(){
    cout<<"hello"<<endl;
    int sockfd;
    struct addrinfo hints, *servinfo,*p;
    int rv;
    int numbytes;



    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;

    if((rv=getaddrinfo("127.0.0.1",PORT,&hints,&servinfo))!=0){
        cout<<"error getaddrinfo "<<gai_strerror(rv)<<endl;
        return 1;
    }

    for(p=servinfo;p!=NULL;p=p->ai_next){
        if((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
            perror("socket");
            continue;
        }
        break;
    }
    if(p==NULL){
        cout<<"error creating socket"<<endl;
        return 2;
    }
    sendFile(sockfd,p);
    freeaddrinfo(servinfo);

    close(sockfd);


};

int FileSender::sendFile(int sockfd, struct addrinfo* p) {
    FILE* f;
    int numbytes;
    string names[]={"wireshark.jpg","team-rocket-2.png","onemb.jpg","test100k.db","file5.zip"};
    int counter=5;
    struct in_addr loopback;
    inet_pton(AF_INET,"127.0.0.1",&loopback);

    for(int i=0;i<5;i++) {
        string name=path;
        name.append(names[i]);
        f = fopen(name.c_str(), "rb");
        if (f == NULL) {
            cout << "fileopen error" << endl;
            return 1;
        }

        fseek(f, 0, SEEK_END);
        long double sz = ftell(f);
        fseek(f, 0, SEEK_SET);
        sz = ceil(sz / MAXDATALEN);
        uint16_t x = 1;
        cout<< "SENDING: "<<names[i]<<endl;
        cout << "NUMBER OF CHUNKS: " << sz << endl;
        sendto(sockfd, &sz, sizeof(sz), 0, p->ai_addr, p->ai_addrlen);
        FILE *t=fopen("/home/aerez/test.txt","w");
        while (x <= sz) {
            char databuffer[MAXDATALEN];
            numbytes = fread(databuffer, 1, MAXDATALEN, f);
            CustomFrame cf(numbytes,databuffer,i,loopback.s_addr,loopback.s_addr,x);
            cout << "\r";
            cout << "Sent(" << x << "/" << sz << ")";
            string frame= cf.serialize_frame();
            if (numbytes > 0) {
                sendto(sockfd, frame.c_str(), frame.size(), 0, p->ai_addr, p->ai_addrlen);
                x++;
                fwrite(databuffer,1,numbytes,t);
            }
            if (numbytes < MAXDATALEN+14) {
                if (feof(f)) {
                    cout<<"COMPLETED" << endl ;

                }
                if (ferror(f))
                    cout << "Error reading" << endl;


            }



        usleep(500);

        }

    }
    }
