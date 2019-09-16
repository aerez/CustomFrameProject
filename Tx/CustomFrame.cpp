//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include "CustomFrame.h"

CustomFrame::CustomFrame(uint8_t sync, uint32_t dst, uint32_t src, uint8_t fileId, uint8_t datasize, char *data) : sync(
        sync), dst(dst), src(src), fileID(fileId), datasize(datasize), data(data) {}

uint8_t CustomFrame::getSync() const {
    return sync;
}

void CustomFrame::setSync(uint8_t sync) {
    CustomFrame::sync = sync;
}

uint32_t CustomFrame::getDst() const {
    return dst;
}

void CustomFrame::setDst(uint32_t dst) {
    CustomFrame::dst = dst;
}

uint32_t CustomFrame::getSrc() const {
    return src;
}

void CustomFrame::setSrc(uint32_t src) {
    CustomFrame::src = src;
}

uint8_t CustomFrame::getFileId() const {
    return fileID;
}

void CustomFrame::setFileId(uint8_t fileId) {
    fileID = fileId;
}

uint8_t CustomFrame::getDatasize() const {
    return datasize;
}

void CustomFrame::setDatasize(uint8_t datasize) {
    CustomFrame::datasize = datasize;
}

char *CustomFrame::getData() const {
    return data;
}

void CustomFrame::setData(char *data) {
    CustomFrame::data = data;
}

template <class T>
unsigned char * serialize_8bit(unsigned char *buffer, T value){
    buffer[0]=value;
    return buffer+1;
}

unsigned char * serialize_32bit(unsigned char *buffer,uint32_t value){
    buffer[0]=value>>24;
    buffer[1]=value>>16;
    buffer[2]=value>>8;
    buffer[3]=value;
    return buffer+4;
}

unsigned char* addData(unsigned char* buffer, char* data,int datasize){
    std::cout<<datasize<<std::endl;
    for(int i=0;i<datasize;i++){
        buffer[i]=data[i];
    }
    return buffer+datasize;
}

unsigned char * serialize_frame(unsigned char *buffer,CustomFrame *value){

    buffer= serialize_8bit(buffer,value->getSync());
    buffer=serialize_32bit(buffer,value->getDst());
    buffer=serialize_32bit(buffer,value->getSrc());
    buffer=serialize_8bit(buffer, value->getFileId());
    buffer= serialize_8bit(buffer, value->getDatasize());
    buffer=addData(buffer,value->getData(),value->getDatasize());

    return buffer;
}