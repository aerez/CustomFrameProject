//
// Created by aerez on 9/16/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <ostream>

#define MAXDATALEN 1024
class CustomFrame {
uint8_t fileID;
uint32_t dst;
uint32_t src;
uint16_t chunkID;
uint16_t datasize;
char data[MAXDATALEN];

public:
    CustomFrame(uint8_t fileID, uint32_t dst, uint32_t src, uint16_t chunkId, uint16_t datasize,char data[]);

    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getfileID() const;

    void setfileID(uint8_t sync);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint16_t getChunkId() const;

    void setChunkId(uint16_t fileId);

    uint16_t getDatasize() const;

    void setDatasize(uint16_t datasize);

    const char *getData() const;

    void setData(char *data);

    std::string serialize_frame();
};


 void serialize_8bit(char *buffer, int value);


 void serialize_32bit(char *buffer,uint32_t value);


 void addData( char* buffer, char* data,uint16_t datasize);






#endif //TX_CUSTOMFRAME_H
