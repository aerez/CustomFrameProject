//
// Created by aerez on 9/16/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H

#include "BasicFrame.h"

#include <stdint.h>
#include <ostream>


class CustomFrame : public BasicFrame {
uint8_t fileID;
uint32_t dst;
uint32_t src;
uint16_t chunkID;


public:

    CustomFrame(uint16_t datalen, char *data, uint8_t fileId, uint32_t dst, uint32_t src,
                uint16_t chunkId);



    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getfileID() const;

    void setfileID(uint8_t sync);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint16_t getChunkId() const;

    void setChunkId(uint16_t fileId);


    std::string serialize_frame();
};












#endif //TX_CUSTOMFRAME_H
