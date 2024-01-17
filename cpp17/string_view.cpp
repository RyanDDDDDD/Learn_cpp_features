#include <iostream>
#include <string>
#include <string_view>

// https://stackoverflow.com/questions/40127965/how-exactly-is-stdstring-view-faster-than-const-stdstring
// https://uint128.com/2022/02/16/C-17-%E7%89%B9%E6%80%A7-%E4%BD%BF%E7%94%A8-std-string-view-%E6%97%B6%E5%B0%8F%E5%BF%83%E8%B8%A9%E5%9D%91/
int main () {
    std::string str{ "foobar" };
    std::string_view bar{ str };
    bar.remove_prefix (3);

    if (bar == "bar") {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not Equal" << std::endl;
    }
}