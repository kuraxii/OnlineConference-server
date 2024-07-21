#include <sstream>
#include <iostream>
#include "src/server/server.h"
int main() {
    server ser;
    ser.init();
    return ser.run();
}