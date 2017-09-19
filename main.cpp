#include <iostream>
#include <vector>

#include "interpolation_search.h"

#define TRY(a) \
    it = Search::interpolation_search(vec.begin(), vec.end(), a);\
    if (it == vec.end()) {\
        std::cout << #a " not found" << std::endl;\
    } else {\
        std::cout << "found " << *it << std::endl;\
    }

int main()
{
    std::vector<int> vec = { -19, -18, -12, -12, -9, -8, -4, -3, -1, -1, 0, 1, 3, 4, 9, 12, 20, 30, 35, 39, 40 };
    std::vector<int>::iterator it;
    TRY(-19);
    TRY(-18);
    TRY(-12);
    TRY(-12);
    TRY(-9);
    TRY(-8);
    TRY(-4);
    TRY(-3);
    TRY(-1);
    TRY(-1);
    TRY(0);
    TRY(1);
    TRY(3);
    TRY(4);
    TRY(9);
    TRY(12);
    TRY(20);
    TRY(30);
    TRY(35);
    TRY(39);
    TRY(40);
    TRY(-1000);
    TRY(-20);
    TRY(-10);
    TRY(36);
    TRY(41);
    TRY(1000);
}
