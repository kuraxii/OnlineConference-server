#include <sstream>
#include <iostream>

int main() {
    std::string str{"123456\r\n123\n"};
    std::istringstream stream{str};
    std::string line;
    while (std::getline(stream, line)) {
        // std::cout << line << "\n";
    }
}