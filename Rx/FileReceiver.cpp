//
// Created by aerez on 9/17/19.
//


#include "FileReceiver.h"

using namespace std;

FileReceiver::FileReceiver(const std::string &path) : path(path) {}

int FileReceiver::Run() {
    int sockfd;
    struct addrinfo hints,*servinfo,*p;
    int rv;
    int numbytes;
    struct sockaddr_storage their_addr;
    unsigned char buffer[MAXBUFLEN];
    socklen_t addr_len;
    char s[INET_ADDRSTRLEN];

    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;

    if((rv=getaddrinfo("127.0.0.1",PORT,&hints,&servinfo))!=0){
        cout<<"getadddrinfo "<<gai_strerror(rv)<<endl;
        return 1;
    }
    for(p=servinfo;p!=NULL;p=p->ai_next){
        if((sockfd= socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
            perror("listerner:socket");
            continue;
        }

        if(bind(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            close(sockfd);
            perror("listener: bind");
            continue;
        }
        break;
    }

    if(p==NULL){
        cout<<"listener failed to bind socket"<<endl;
        return 2;
    }
    freeaddrinfo(servinfo);

    receiveFile(sockfd,1);
}

int FileReceiver::receiveFile(int sockfd,int filenum) {
    struct sockaddr_storage their_addr;

    socklen_t addr_len;
    int byteReceieved;
    FILE *f;
    string name="file";
    name.append(to_string(filenum)+".txt");
    cout<<"receiving file"<<endl;
    path.append(name);
    f=fopen(path.c_str(),"wb");
    if(f==NULL){
        cout<<"Error opening file";
        return 1;
    }
    double numberofchunks;
    recvfrom(sockfd,&numberofchunks,sizeof(numberofchunks),0,(struct sockaddr*)&their_addr,&addr_len);
    int x=1;
   while(x<=numberofchunks){
       unsigned char buffer[512]={0};
       byteReceieved= recvfrom(sockfd,buffer,512,0,(struct sockaddr*)&their_addr,&addr_len);
       CustomFrame* cf= new CustomFrame(buffer);
       //cout<<*cf<<"--------------------"<<endl;
       cout<<"Received ("<<x<<"/"<<numberofchunks<<")"<<endl;
       fwrite(cf->getData(),1,cf->getDatasize(),f);
       x++;
   }

    if(byteReceieved<0)
        cout<<endl<<"READ ERROR"<<endl;

    cout<<"FILE COMPLETED"<<endl;

    return 0;

}
