#include <iostream>
#include "FileSender.h"
int main() {
    FileSender fs("config.txt");
    fs.Run();
    return 0;
}