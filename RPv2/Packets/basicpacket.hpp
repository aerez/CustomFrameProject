#ifndef BASICPACKET_HPP
#define BASICPACKET_HPP


#include <QDebug>



enum Types {Data, KeepAlive,Info};

#define MAXDATALEN 1024

class BasicPacket
{
protected:
    Types messageTypes;
    char data[MAXDATALEN];
    uint16_t datalen=0;
public:
    BasicPacket (Types messageType,uint16_t, char data[]);

    void serialize_8bit(char *buffer, uint8_t value);


    void serialize_32bit(char *buffer,uint32_t value);


    void serialize_16bit(char* buffer,uint16_t value);

    uint32_t deserialize32bit(char* buffer);


    uint16_t deserialize16(char* buffer);

    const char * getData() const;

    uint16_t getDatalen() const;

    virtual std::string serialize_frame()=0;

    Types getType();



};

#endif // BASICPACKET_HPP
