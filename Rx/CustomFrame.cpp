//
// Created by aerez on 9/17/19.
//


#include "CustomFrame.h"

uint32_t deserialize32bit(char* buffer){
    uint32_t ret= (buffer[0]<<24)|(buffer[1]<<16)|(buffer[2]<<8)|(buffer[3]);
    return ret;
}

uint16_t deserialize16(char* buffer){
    uint8_t msb,lsb;
    msb=buffer[0];
    lsb=buffer[1];
    uint16_t ret= (msb<<8)| lsb ;
    return ret;
}

CustomFrame::CustomFrame(char *buffer) {
    fileID=buffer[0];
    dst= deserialize32bit(buffer+1);
    src=deserialize32bit(buffer+5);
    chunkID=deserialize16(buffer+9);
    datasize=deserialize16(buffer+11);
    //std::cout<<"datasize "<<datasize<<std::endl;
    for(uint16_t i=0;i<datasize;i++){
        data[i]=buffer[13+i];
    }

}

void CustomFrame::showData() {
    for(int i=0;i<datasize;i++){
        std::cout<<data[i];
    }
}

char* CustomFrame::getData() {
    return data;
}

void CustomFrame::print_ip(uint32_t ip) {
    char bytes[4];
    bytes[0]= ip & 0xFF;
    bytes[1]=(ip>>8)&0xFF;
    bytes[2]=(ip>>16)&0xFF;
    bytes[3]=(ip>>24)&0xFF;
    std::cout<<(int)bytes[0]<<'.'<<(int)bytes[1]<<'.'<<(int)bytes[2]<<'.'<<(int)bytes[3]<<std::endl;
}



uint8_t CustomFrame::getFileID() const {
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
    chunkId = chunkId;
}

uint16_t CustomFrame::getDatasize() const {
    return datasize;
}

void CustomFrame::setDatasize(uint16_t datasize) {
    CustomFrame::datasize = datasize;
}

std::ostream &operator<<(std::ostream &os, const CustomFrame &frame) {
    os << "sync: " << frame.fileID << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datasize << " data: " << frame.data;
    return os;
}





