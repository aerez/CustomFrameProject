//
// Created by aerez on 9/17/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <iostream>

#include "CustomFrame.h"


#ifndef RX_FILERECEIVER_H
#define RX_FILERECEIVER_H

#define PORT "4950"

#define MAXBUFLEN 255

class FileReceiver {
std::string path;
public:
    FileReceiver(const std::string &path);

    int Run();

    int receiveFile(int sockfd,int filenum);

    int listener(int sock);
};


#endif //RX_FILERECEIVER_H
