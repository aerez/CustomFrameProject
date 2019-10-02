//
// Created by aerez on 9/24/19.
//

#ifndef TX_KEEPALIVEFRAME_H
#define TX_KEEPALIVEFRAME_H


#include "BasicFrame.h"

class KeepAliveFrame : public BasicFrame{
public:
    KeepAliveFrame();

    std::string serialize_frame();
};


#endif //TX_KEEPALIVEFRAME_H
