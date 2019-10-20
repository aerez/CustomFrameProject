#include <iostream>
#include "FileReceiver.h"
int main() {
    FileReceiver fr("config.txt");
    fr.Run();
    return 0;
}