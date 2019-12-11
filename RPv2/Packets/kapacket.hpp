#ifndef KAPACKET_HPP
#define KAPACKET_HPP

#include <QObject>
#include "Packets/basicpacket.hpp"

class KAPacket : public BasicPacket
{
public:
    KAPacket();

    std::string serialize_frame() override;


};

#endif // KAPACKET_HPP
