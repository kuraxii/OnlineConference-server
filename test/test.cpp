#include <iostream>
// #include <test.pb.h>
int main()
{
    
    Person p;
    p.set_age(32);
    p.set_id(12345);
    p.set_name("zzj");
    p.set_sex("xy");

    std::string str;
    p.SerializeToString(&str);

    std::cout << str << std::endl;
    return 0;
}