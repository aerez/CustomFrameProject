#include "kapacket.hpp"

KAPacket::KAPacket() : BasicPacket(KeepAlive, 0,0) {}

std::string KAPacket::serialize_frame() {
    char buffer[1];
    serialize_8bit(buffer,messageTypes);

    std::string frame= std::string(buffer,1);

    return frame;
}
