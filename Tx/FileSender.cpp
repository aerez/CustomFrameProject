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

    path.append("sample.txt");

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
    struct in_addr loopback;
    inet_pton(AF_INET,"127.0.0.1",&loopback);
    f= fopen(path.c_str(),"rb");
    if(f==NULL){
        cout<<"fileopen error"<<endl;
        return 1;
    }

    fseek(f,0,SEEK_END);
    double sz=ftell(f);

    fseek(f,0,SEEK_SET);

    sz= ceil(sz/MAXDATALEN);
    int x=1;
    cout<<"NUMBER OF CHUNKS: "<<sz<<endl<<endl;
    sendto(sockfd,&sz,sizeof(sz),0,p->ai_addr,p->ai_addrlen);
    while(x<=sz) {
        char databuffer[MAXDATALEN]={0};
        numbytes= fread(databuffer,1,255,f);
        cout<<endl<<"numbytes: "<<numbytes<<endl;
        CustomFrame cf('$', loopback.s_addr, loopback.s_addr, 1, numbytes, databuffer);
        //cout<<cf<<endl;
        cout<<"Received ("<<x<<"/"<<sz<<")"<<endl;

        //cout<<"sizeofcf: "<<sizeof(cf)<<endl;
        unsigned char *ptr, buffer[512];
        ptr = serialize_frame(buffer, &cf);
        int size = ptr - buffer;
        //cout<<"size: "<<size<<endl;
        if(numbytes>0){
            sendto(sockfd,buffer,size,0,p->ai_addr,p->ai_addrlen);
        }
        if(numbytes<255){
            if(feof(f)){
                cout<<"end of file"<<endl<<"Complete";

            }
            if(ferror(f))
                cout<<"Error reading"<<endl;


        }

        x++;
    }
    }
