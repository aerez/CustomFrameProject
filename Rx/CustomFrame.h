//
// Created by aerez on 9/17/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <iostream>

#define MAXDATALEN 2056
class CustomFrame {
    uint8_t sync;
    uint32_t dst;
    uint32_t src;
    uint8_t fileID;
    uint16_t datasize;
    char data[MAXDATALEN];

public:


    CustomFrame(unsigned char* buffer);

    void showData();

    void print_ip(uint32_t ip);

    char* getData();

    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getSync() const;

    void setSync(uint8_t sync);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint8_t getFileId() const;

    void setFileId(uint8_t fileId);

    uint16_t getDatasize() const;

    void setDatasize(uint16_t datasize);


};

uint32_t deserialize32bit(unsigned char* buffer);

#endif //TX_CUSTOMFRAME_H