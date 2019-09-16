//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include "FileSender.h"


using namespace std;

FileSender::FileSender(char *path) : path(path){};

int FileSender::Run(){
    cout<<"hello"<<endl;
    int sockfd;
    struct addrinfo hints, *servinfo,*p;
    int rv;
    int numbytes;

    char data[]="hello";

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
    struct in_addr loopback;
    inet_pton(AF_INET,"127.0.0.1",&loopback);
    cout<<sizeof data<<endl;
    CustomFrame cf('$',loopback.s_addr,loopback.s_addr,1,sizeof data, data);
    unsigned char *ptr,buffer[100];
    ptr= serialize_frame(buffer,&cf);
    int size= ptr-buffer;
    cout<<size<<endl;
    for(int i=0;i<size-1;i++){
        cout<<buffer[i];
    }
    if((numbytes=sendto(sockfd,buffer,size,0,p->ai_addr,p->ai_addrlen)==-1){
        perror("sendto");
        exit(1);
    }

    freeaddrinfo(servinfo);

    close(sockfd);


};