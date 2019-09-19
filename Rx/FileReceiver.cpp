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
    string names[]={"wireshark.jpg","team-rocket-2.png","onemb.jpg","test100k.db","file5.zip"};
    int byteReceieved;
    for(int i=0;i<5;i++){
    FILE *f;
    string name=path;
    name.append(names[i]);
    cout<<"receiving file "<<names[i]<<endl;
    f=fopen(name.c_str(),"wb");
    if(f==NULL){
        cout<<"Error opening file";
        return 1;
    }
    fseek(f,0,SEEK_SET);
    long double numberofchunks;
    recvfrom(sockfd,&numberofchunks,sizeof(numberofchunks),0,(struct sockaddr*)&their_addr,&addr_len);
    long double x=1;
   while(x<=numberofchunks){
       char buffer[MAXDATALEN+13]={0};
       byteReceieved= recvfrom(sockfd,buffer,MAXDATALEN+13,0,(struct sockaddr*)&their_addr,&addr_len);
       CustomFrame* cf= new CustomFrame(buffer);
       cout << "\r";
       cout<<"Received ("<<x<<"/"<<numberofchunks<<")";
       fseek(f, cf->getChunkId()*MAXDATALEN,SEEK_SET);
       fwrite(cf->getData(),1,cf->getDatasize(),f);

       x++;
   }

    if(byteReceieved<0)
        cout<<endl<<"READ ERROR"<<endl;

    cout<<"FILE COMPLETED"<<endl;
    fclose(f);
    }

    return 0;

}
