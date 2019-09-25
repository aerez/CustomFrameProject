//
// Created by aerez on 9/24/19.
//
#include "BasicFrame.h"
#include <cstring>


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

uint32_t BasicFrame::deserialize32bit(char* buffer){
    uint32_t ret= (buffer[0]<<24)|(buffer[1]<<16)|(buffer[2]<<8)|(buffer[3]);
    return ret;
}

uint16_t BasicFrame::deserialize16(char* buffer){
    uint8_t msb,lsb;
    msb=buffer[0];
    lsb=buffer[1];
    uint16_t ret= (msb<<8)| lsb ;
    return ret;
}

const char* BasicFrame::getData() const {
    return data;
}


uint16_t BasicFrame::getDatalen() const {
    return datalen;
}

void BasicFrame::setDatalen(uint16_t datalen) {
    BasicFrame::datalen = datalen;
}
