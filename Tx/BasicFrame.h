//
// Created by aerez on 9/24/19.
//

#include <cstdint>
#include <string>

enum Types {FileData, KeepAlive};

#ifndef CUSTOMFRAMEPROJECT_BASICFRAME_H
#define CUSTOMFRAMEPROJECT_BASICFRAME_H

#define MAXDATALEN 1024

class BasicFrame{
protected:
    Types messageTypes;
    char data[MAXDATALEN];
    uint16_t datalen=0;
public:
    BasicFrame (Types messageType,uint16_t, char data[]);

    void serialize_8bit(char *buffer, uint8_t value);


    void serialize_32bit(char *buffer,uint32_t value);


    void serialize_16bit(char* buffer,uint16_t value);

    virtual std::string serialize_frame()=0;
};


#endif //CUSTOMFRAMEPROJECT_BASICFRAME_H
