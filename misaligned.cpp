#include <assert.h>
#include <iostream>
#include <map>
#include <string>
enum MajorColor{ White = 0, Red, Black, Yellow, Violet };
enum MinorColor{ Blue = 0, Orange, Green, Brown, Slate };
const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

std::map <std::string , MajorColor> majorColorEnumtoStringMap;
std::map <std::string , MinorColor> minorColorEnumtoStringMap;

void mapMajorarraytoEnum() {
    for (int i = 0; i < numberOfMajorColors; i++) {
        majorColorEnumtoStringMap.insert({ majorColor[i] , (MajorColor)i });
    }
}

void mapMinorarraytoEnum() {
    for (int i = 0; i < numberOfMinorColors; i++) {
        minorColorEnumtoStringMap.insert({ minorColor[i] , (MinorColor)i });
    }
}

int mapColorToNumber(MajorColor majorColor, MinorColor minorColor) {
    int pairNumber = majorColor * 5 + minorColor;
    return pairNumber;
}

int printColorMap() {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            int pairNumber = mapColorToNumber(majorColorEnumtoStringMap[majorColor[i]] ,
                                                minorColorEnumtoStringMap[minorColor[i]]);
            assert(pairNumber == (i * 5 + j));
        }
    }
    return i * j;
}


int main() {
    mapMajorarraytoEnum();
    mapMinorarraytoEnum();
    int pairNumber = mapColorToNumber(MajorColor::White, MinorColor::Orange);
    assert(pairNumber == 1);
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
