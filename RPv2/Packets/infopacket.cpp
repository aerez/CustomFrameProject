#include "infopacket.hpp"

infopacket::infopacket(uint16_t sizeofname, char* filename,uint8_t fileID, uint16_t chunks )
    : BasicPacket(Info,sizeofname,filename)
{
    this->fileID=fileID;
    this->chunks=chunks;
}

infopacket::infopacket(char *buffer) : BasicPacket((Types)buffer[0],deserialize16(buffer+4),buffer+6){
    fileID=buffer[1];
    chunks=deserialize16(buffer+2);

    //std::cout<<"datasize "<<datasize<<std::endl;


}

uint8_t infopacket::getfileID(){
    return fileID;
}

uint16_t infopacket::getchunks(){
    return chunks;
}

std::string infopacket::serialize_frame(){
    char buffer[datalen+6];
    serialize_8bit(buffer,messageTypes);
    serialize_8bit(buffer+1,fileID);
    serialize_16bit(buffer+2, chunks);
    serialize_16bit(buffer+4,datalen);
    for(int i=0;i<datalen;i++){
        buffer[i+6]=data[i];
    }

    std::string packet= std::string(buffer,datalen+6);

    return packet;

}
