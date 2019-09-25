//
// Created by aerez on 9/17/19.
//


#include "CustomFrame.h"



CustomFrame::CustomFrame(char *buffer) : BasicFrame((Types)buffer[0],deserialize16(buffer+12),buffer+14){
    fileID=buffer[1];
    dst= deserialize32bit(buffer+2);
    src=deserialize32bit(buffer+6);
    chunkID=deserialize16(buffer+10);

    //std::cout<<"datasize "<<datasize<<std::endl;


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


std::ostream &operator<<(std::ostream &os, const CustomFrame &frame) {
    os << "sync: " << frame.fileID << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datalen << " data: " << frame.data;
    return os;
}

std::string CustomFrame::serialize_frame(){

    char buffer[datalen+14];
    serialize_8bit(buffer,messageTypes);
    serialize_8bit(buffer+1,fileID);
    serialize_32bit(buffer+2, dst);
    serialize_32bit(buffer+6, src);
    serialize_16bit(buffer+10,chunkID);
    serialize_16bit(buffer+12,datalen);

    int counter=0;
    for(int i=0;i<datalen;i++){
        counter++;
        buffer[i+14]=data[i];
    }
    std::string frame=std::string(buffer, datalen+14);


    return frame;
}





