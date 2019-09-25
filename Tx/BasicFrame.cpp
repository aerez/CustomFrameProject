//
// Created by aerez on 9/24/19.
//

#include <cstring>
#include "BasicFrame.h"

BasicFrame::BasicFrame(Types messageType, uint16_t datalen, char *data) : messageTypes(messageType), datalen(datalen){
    for(int i=0;i<datalen;i++){
        (this->data)[i]=data[i];
    }
}

    void BasicFrame::serialize_8bit(char *buffer, uint8_t value){
        buffer[0]=value;

    }

    void BasicFrame::serialize_32bit(char* buffer,uint32_t value){

        buffer[0]=value>>24;
        buffer[1]=value>>16;
        buffer[2]=value>>8;
        buffer[3]=value;

    }

    void BasicFrame::serialize_16bit(char* buffer,uint16_t value){
        buffer[0]=value>>8;
        buffer[1]=value;

    }



