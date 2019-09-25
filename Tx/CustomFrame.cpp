//
// Created by aerez on 9/16/19.
//

#include <iostream>
#include <cstring>
#include "CustomFrame.h"




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



std::ostream &operator<<(std::ostream &os, const CustomFrame &frame) {

    os << "sync: " << frame.fileID << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datalen << " data: " << frame.data;
    return os;
}

CustomFrame::CustomFrame(uint16_t datalen, char *data, uint8_t fileId, uint32_t dst, uint32_t src,
                         uint16_t chunkId) : BasicFrame(FileData, datalen, data), fileID(fileId), dst(dst),
                                             src(src), chunkID(chunkId) {}






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