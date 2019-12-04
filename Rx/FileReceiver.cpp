//
// Created by aerez on 9/17/19.
//


#include <fstream>
#include <sstream>
#include "FileReceiver.h"

using namespace std;

string names[]={"wireshark.jpg","team-rocket-2.png","onemb.jpg","test100k.db","file5.zip"};


FileReceiver::FileReceiver(std::string filename) {
    ifstream file(filename.c_str());
    string line;

    if(file.is_open()){
    while(getline(file,line)){
        istringstream is_line(line);
        string key;
        if(getline(is_line,key,'='))
        {
            string value;
            if(getline(is_line,value)){
                if(key=="ip")
                    ip=value;
                if(key=="port")
                    port=value;
                if(key=="path")
                    path=value;
            }
        }


        }
    file.close();

    }
    else cout<<"Unable to open file";


}



int FileReceiver::Run() {
    int sockfd;
    struct addrinfo hints,*servinfo,*p;
    int rv;




    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;

    cout<<"ip:"<<ip<<endl;
    cout<<"path:"<<path<<endl;
    cout<<"port:"<<port<<endl;


    if((rv=getaddrinfo(ip.c_str(),port.c_str(),&hints,&servinfo))!=0){
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

    listener(sockfd);
}

int FileReceiver::listener(int sock) {
    for(int i=0;i<1;i++){
        receiveFile(sock, i);
    }
}

int FileReceiver::receiveFile(int sockfd,int filenum) {
    struct sockaddr_storage their_addr;
    socklen_t addr_len;


    int byteReceieved;

    FILE *f;
    string name=path;
    name.append(names[filenum]);
    cout<<"receiving file "<<names[filenum]<<endl;
    f=fopen(name.c_str(),"wb");
    if(f==NULL){
        cout<<"Error opening file";
        return 1;
    }
    fseek(f,0,SEEK_SET);
    char b[10]={0};
    recvfrom(sockfd,b,10,0,(struct sockaddr*)&their_addr,&addr_len);
    long double numberofchunks;
    recvfrom(sockfd,&numberofchunks,sizeof numberofchunks,0,(struct sockaddr*)&their_addr,&addr_len);
    uint16_t x=1;
    while(x<=numberofchunks){
        char buffer[MAXDATALEN+14]={0};
    byteReceieved= recvfrom(sockfd,buffer,MAXDATALEN+14,0,(struct sockaddr*)&their_addr,&addr_len);
    if(buffer[0]==KeepAlive)
    {
        cout<<"received KEEPALIVE"<<endl;
    }
    else if(buffer[0]==FileData) {


        
        CustomFrame *cf = new CustomFrame(buffer);
        //cout << "\r";
        cout << "Received (" << x << "/" << numberofchunks << ")"<<endl;
        fwrite(cf->getData(), 1, cf->getDatalen(), f);

        x++;
    }

        if(byteReceieved<0)
            cout<<endl<<"READ ERROR"<<endl;


    }

    cout<<"FILE COMPLETED"<<endl;
    fclose(f);




    return 0;

}
