//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include <cstring>
#include "CustomFrame.h"

CustomFrame::CustomFrame(uint8_t fileID, uint32_t dst, uint32_t src, uint16_t chunkId, uint16_t datasize,char data[MAXDATALEN]): fileID(
        fileID), dst(dst), src(src), chunkID(chunkId), datasize(datasize) {
    for(int i=0;i<datasize;i++){
        (this->data)[i]=data[i];
    }

}

uint8_t CustomFrame::getfileID() const {
    return fileID;
}

void CustomFrame::setfileID(uint8_t fileID) {
    CustomFrame::fileID = fileID;
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

uint16_t CustomFrame::getChunkId() const {
    return chunkID;
}

void CustomFrame::setChunkId(uint16_t chunkId) {
    chunkID = chunkId;
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

void CustomFrame::setData(char data[]) {
    strcpy(this->data,data);
}

std::ostream &operator<<(std::ostream &os, const CustomFrame &frame) {

    os << "sync: " << frame.fileID << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datasize << " data: " << frame.data;
    return os;
}


void serialize_8bit(char *buffer, int value){
    buffer[0]=value;

}

void serialize_32bit(char* buffer,uint32_t value){

    buffer[0]=value>>24;
    buffer[1]=value>>16;
    buffer[2]=value>>8;
    buffer[3]=value;

}

void serialize_16bit(char* buffer,uint16_t value){
    buffer[0]=value>>8;
    buffer[1]=value;

}



std::string CustomFrame::serialize_frame(){

    char buffer[datasize+13];
    serialize_8bit(buffer,fileID);
    serialize_32bit(buffer+1, dst);
    serialize_32bit(buffer+5, src);
    serialize_16bit(buffer+9,chunkID);
    serialize_16bit(buffer+11,datasize);

    int counter=0;
    for(int i=0;i<datasize;i++){
        counter++;
        buffer[i+13]=data[i];
    }
    std::string frame=std::string(buffer, datasize+13);


    return frame;
}