//
// Created by aerez on 9/16/19.
//


#include <fstream>
#include <sstream>
#include "FileSender.h"


using namespace std;

FileSender::FileSender(string filename){
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



int FileSender::Run(){
    cout<<"hello"<<endl;
    int sockfd;
    struct addrinfo hints, *servinfo,*p;
    int rv;




    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;

    if((rv=getaddrinfo(ip.c_str(),port.c_str(),&hints,&servinfo))!=0){
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
    inet_pton(AF_INET,ip.c_str(),&loopback);

    for(int i=0;i<1;i++) {
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

            }
            if (numbytes < MAXDATALEN+14) {
                if (feof(f)) {
                    cout<<"COMPLETED" << endl ;

                }
                if (ferror(f))
                    cout << "Error reading" << endl;


            }

            if(x%3==0)
                sendKeepAlive(sockfd,p);



        usleep(100000);

        }

    }
    }

int FileSender::sendKeepAlive(int sockfd, struct addrinfo *p) {
    KeepAliveFrame ka;
    string msg= ka.serialize_frame();
    sendto(sockfd, msg.c_str(),msg.size(),0,p->ai_addr,p->ai_addrlen);
    //usleep(3000);
}