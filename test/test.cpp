#include <iostream>
#include <test.pb.h>
#include <unistd.h>

#include "../src/net.h"
int main()
{

    // Person p;
    // p.set_age(32);
    // p.set_id(12345);
    // p.set_name("zzj");
    // p.set_sex("xy");

    // std::string str;
    // p.SerializeToString(&str);

    // std::cout << str << std::endl;
    UDPManager::getInstance();

 

    while (1) {
        sleep(1);
    }

    return 0;
}