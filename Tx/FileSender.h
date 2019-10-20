//
// Created by aerez on 9/16/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <cmath>


#include "CustomFrame.h"
#include "KeepAliveFrame.h"

#ifndef TX_FILESENDER_H
#define TX_FILESENDER_H



#define PORT "4950"

class FileSender {
std::string path;
std::string ip;
std::string port;

public:
    FileSender(std::string filename);

    int Run();

    int sendFile(int sock, struct addrinfo* p);

    int sendKeepAlive(int sock, struct addrinfo* p);
};


#endif //TX_FILESENDER_H
