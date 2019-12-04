#include "datapacket.hpp"


uint8_t DataPacket::getfileID() const {
    return fileID;
}

void DataPacket::setfileID(uint8_t fileID) {
    DataPacket::fileID = fileID;
}

uint32_t DataPacket::getDst() const {
    return dst;
}

void DataPacket::setDst(uint32_t dst) {
    DataPacket::dst = dst;
}

uint32_t DataPacket::getSrc() const {
    return src;
}

void DataPacket::setSrc(uint32_t src) {
    DataPacket::src = src;
}

uint16_t DataPacket::getChunkId() const {
    return chunkID;
}

void DataPacket::setChunkId(uint16_t chunkId) {
    chunkID = chunkId;
}



std::ostream &operator<<(std::ostream &os, const DataPacket &frame) {

    os << "sync: " << frame.fileID << " dst: " << frame.dst << " src: " << frame.src << " fileID: " << (int)frame.fileID
       << " datasize: " << (int)frame.datalen << " data: " << frame.data;
    return os;
}

DataPacket::DataPacket(uint16_t datalen, char *data, uint8_t fileId, uint32_t dst, uint32_t src,
                         uint16_t chunkId) : BasicPacket(FileData, datalen, data), fileID(fileId), dst(dst),
                                             src(src), chunkID(chunkId) {}






std::string DataPacket::serialize_frame(){

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
