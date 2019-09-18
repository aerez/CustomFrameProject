//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include <cstring>
#include "CustomFrame.h"

CustomFrame::CustomFrame(uint8_t sync, uint32_t dst, uint32_t src, uint8_t fileId, uint16_t datasize, char data[]) : sync(
        sync), dst(dst), src(src), fileID(fileId), datasize(datasize) {strcpy(this->data,"");strncpy(this->data,data,datasize);}

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

uint16_t CustomFrame::getDatasize() const {
    return datasize;
}

void CustomFrame::setDatasize(uint16_t datasize) {
    CustomFrame::datasize = datasize;
}

const char *CustomFrame::getData() const {
    return data;
}

void CustomFrame::setData(char *data) {
    strcpy(this->data,data);
}

std::ostream &operator<<(std::ostream &os, const CustomFrame &frame) {

    os << "sync: " << frame.sync << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datasize << " data: " << frame.data;
    return os;
}


 char * serialize_8bit(char *buffer, int value){
    buffer[0]=value;
    return buffer+1;
}

char * serialize_32bit(char *buffer,uint32_t value){
    buffer[0]=value>>24;
    buffer[1]=value>>16;
    buffer[2]=value>>8;
    buffer[3]=value;
    return buffer+4;
}

char * serialize_16bit(char *buffer, uint16_t value){
    //std::cout<<"TESTTT: "<<value<<std::endl;
    buffer[0]=value>>8;
    buffer[1]=value;

    return buffer+2;
}

char* addData(char* buffer, const char* data,uint16_t datasize){

    for(uint16_t i=0;i<datasize;i++){
        buffer[i]=data[i];
        //std::cout<<data[i];
    }

    //std::cout<<std::endl<<datasize<<std::endl<<"SIZEEEEEE"<<(int)((buffer+datasize)-buffer)<<std::endl;
    return buffer+datasize;
}

char * serialize_frame(char *buffer,CustomFrame *value){

    buffer= serialize_8bit(buffer,value->getSync());
    buffer=serialize_32bit(buffer,value->getDst());
    buffer=serialize_32bit(buffer,value->getSrc());
    buffer=serialize_8bit(buffer, value->getFileId());
    buffer= serialize_16bit(buffer, value->getDatasize());
    buffer=addData(buffer,value->getData(),value->getDatasize());

    return buffer;
}