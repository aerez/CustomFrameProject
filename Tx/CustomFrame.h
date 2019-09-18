//
// Created by aerez on 9/16/19.
//

#ifndef TX_CUSTOMFRAME_H
#define TX_CUSTOMFRAME_H


#include <stdint.h>
#include <ostream>

#define MAXDATALEN 2056
class CustomFrame {
uint8_t sync;
uint32_t dst;
uint32_t src;
uint8_t fileID;
uint16_t datasize;
char data[MAXDATALEN];

public:
    CustomFrame(uint8_t sync, uint32_t dst, uint32_t src, uint8_t fileId, uint16_t datasize, char *data);

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

    const char *getData() const;

    void setData(char *data);
};


char * serialize_8bit(char *buffer, int value);


 char * serialize_32bit(char *buffer,uint32_t value);


 char* addData( char* buffer, char* data,uint16_t datasize);

 char * serialize_frame(char *buffer,CustomFrame *value);




#endif //TX_CUSTOMFRAME_H
