#ifndef INFOPACKET_HPP
#define INFOPACKET_HPP

#include "Packets/basicpacket.hpp"

class infopacket : public BasicPacket
{
    uint8_t fileID;
    uint16_t chunks;

public:
    infopacket(uint16_t sizeofname, char* filename,uint8_t fileID, uint16_t chunks );

    infopacket(char* buffer);

    uint8_t getfileID();

    uint16_t getchunks();
    std::string serialize_frame() override;
};

#endif // INFOPACKET_HPP
