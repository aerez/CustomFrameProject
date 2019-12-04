#ifndef BASICPACKET_HPP
#define BASICPACKET_HPP

#include <QObject>
#include <QDebug>



enum Types {FileData, KeepAlive};
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

    virtual std::string serialize_frame()=0;



};

#endif // BASICPACKET_HPP
