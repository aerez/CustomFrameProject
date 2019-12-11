#ifndef DATAPACKET_HPP
#define DATAPACKET_HPP

#include "Packets/basicpacket.hpp"

#include <stdint.h>
#include <ostream>

class DataPacket : public BasicPacket
{
public:
    uint8_t fileID;
    uint32_t dst;
    uint32_t src;
    uint16_t chunkID;


    public:

        DataPacket(uint16_t datalen, char *data, uint8_t fileId, uint32_t dst, uint32_t src,
                    uint16_t chunkId);

        DataPacket(char* buffer);

        friend std::ostream &operator<<(std::ostream &os, const DataPacket &frame);

        uint8_t getfileID() const;

        void setfileID(uint8_t sync);

        uint32_t getDst() const;

        void setDst(uint32_t dst);

        uint32_t getSrc() const;

        void setSrc(uint32_t src);

        uint16_t getChunkId() const;

        void setChunkId(uint16_t fileId);


        std::string serialize_frame() override;
};

#endif // DATAPACKET_HPP
