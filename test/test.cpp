#include <iostream>
#include <test.pb.h>
#include <unistd.h>

#include "../src/net.h"
#include "../src/http/ConnectHttp.h"
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
    // UDPManager::getInstance();

    ConnectHttp client;

    // Perform a GET request
    HttpRequest getRequest("http://www.example.com");
    HttpResponse getResponse = client.get(getRequest);
    std::cout << "GET Response Status: " << getResponse.getStatusCode() << std::endl;
    std::cout << "GET Response Body: " << std::string(getResponse.getBody().begin(), getResponse.getBody().end())
              << std::endl;

    // // Perform a POST request with binary data
    // std::vector<char> postData = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // "Hello" in binary
    // HttpRequest postRequest("http://www.example.com", {{"Content-Type", "application/octet-stream"}}, postData);
    // HttpResponse postResponse = client.post(postRequest);
    // std::cout << "POST Response Status: " << postResponse.getStatusCode() << std::endl;
    // std::cout << "POST Response Body: " << std::string(postResponse.getBody().begin(), postResponse.getBody().end())
    //           << std::endl;

    // while (1) {
    //     sleep(1);
    // }

    return 0;
}