//
// Created by aerez on 9/17/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <iostream>
#include "BasicFrame.h"


class CustomFrame : public BasicFrame{
    uint8_t fileID;
    uint32_t dst;
    uint32_t src;
    uint16_t chunkID;


public:


    CustomFrame(char* buffer);


    std::string serialize_frame();



    void print_ip(uint32_t ip);



    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getFileID() const;

    void setfileID(uint8_t fileID);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint16_t getChunkId() const;

    void setChunkId(uint16_t chunkId);






};



#endif //TX_CUSTOMFRAME_H