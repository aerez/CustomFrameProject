//
// Created by aerez on 9/17/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <iostream>

#define MAXDATALEN 1024
class CustomFrame {
    uint8_t fileID;
    uint32_t dst;
    uint32_t src;
    uint16_t chunkID;
    uint16_t datasize;
    char data[MAXDATALEN];

public:


    CustomFrame(char* buffer);

    void showData();

    void print_ip(uint32_t ip);

    char* getData();

    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getFileID() const;

    void setfileID(uint8_t fileID);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint16_t getChunkId() const;

    void setChunkId(uint16_t chunkId);

    uint16_t getDatasize() const;

    void setDatasize(uint16_t datasize);


};

uint32_t deserialize32bit(char* buffer);

#endif //TX_CUSTOMFRAME_H