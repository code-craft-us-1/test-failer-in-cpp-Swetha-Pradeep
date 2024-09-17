#include <assert.h>
#include <iostream>

enum MajorColor{ White=0, Red, Black, Yellow, Violet };
enum MinorColor{ Blue=0, Orange, Green, Brown, Slate };

int printColorMap() {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int mapColorToNumber(MajorColor majorColor, MinorColor minorColor) {
    int pairNumber = majorColor * 5 + minorColor;
    return pairNumber;
}
int main() {
    int pairNumber = mapColorToNumber(MajorColor::White, MinorColor::Orange);
    assert(pairNumber == 1);
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
