//
// Created by aerez on 9/16/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <ostream>

#define MAXDATALEN 255
class CustomFrame {
uint8_t sync;
uint32_t dst;
uint32_t src;
uint8_t fileID;
uint8_t datasize;
char data[MAXDATALEN];

public:
    CustomFrame(uint8_t sync, uint32_t dst, uint32_t src, uint8_t fileId, uint8_t datasize, char *data);

    friend std::ostream &operator<<(std::ostream &os, const CustomFrame &frame);

    uint8_t getSync() const;

    void setSync(uint8_t sync);

    uint32_t getDst() const;

    void setDst(uint32_t dst);

    uint32_t getSrc() const;

    void setSrc(uint32_t src);

    uint8_t getFileId() const;

    void setFileId(uint8_t fileId);

    uint8_t getDatasize() const;

    void setDatasize(uint8_t datasize);

    const char *getData() const;

    void setData(char *data);
};


unsigned char * serialize_8bit(unsigned char *buffer, int value);


unsigned char * serialize_32bit(unsigned char *buffer,uint32_t value);


unsigned char* addData(unsigned char* buffer, char* data,int datasize);

unsigned char * serialize_frame(unsigned char *buffer,CustomFrame *value);




#endif //TX_CUSTOMFRAME_H
