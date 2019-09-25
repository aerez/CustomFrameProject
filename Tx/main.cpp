#include <iostream>
#include "FileSender.h"
int main() {
    FileSender fs("/home/aerez/CLionProjects/CustomFrameProject/Tx/filetosend/");
    fs.Run();
    return 0;
}