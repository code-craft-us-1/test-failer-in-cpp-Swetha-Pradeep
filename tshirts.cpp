#include <assert.h>
#include <iostream>

std::string size(int cms) {
    std::string sizeName = "INVALID";
    if (cms >0 && cms < 38) {
        sizeName = "S";
    } else if (cms > 38 && cms <=42) {
        sizeName = "M";
    } else if (cms > 42) {
        sizeName = "L";
    }
    return sizeName;
}

int main() {
    assert(size(0) == "INVALID");
    assert(size(37) == "S");
    assert(size(40) == "M");
    assert(size(43) == "L");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
