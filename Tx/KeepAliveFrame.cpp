//
// Created by aerez on 9/24/19.
//

#include "KeepAliveFrame.h"

KeepAliveFrame::KeepAliveFrame() : BasicFrame(KeepAlive, 0,0) {}

std::string KeepAliveFrame::serialize_frame() {
    char buffer[1];
    serialize_8bit(buffer,messageTypes);

    std::string frame= std::string(buffer,1);
    return frame;
}
