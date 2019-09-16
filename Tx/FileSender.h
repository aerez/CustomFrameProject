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

#include "CustomFrame.h"

#ifndef TX_FILESENDER_H
#define TX_FILESENDER_H



#define PORT "4950"

class FileSender {
char* path;

public:
    FileSender(char* path);

    int Run();
};


#endif //TX_FILESENDER_H
