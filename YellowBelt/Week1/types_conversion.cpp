//
// Created by mikhail on 24.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <limits>

using namespace std;

int main() {
    cout << numeric_limits<int>::max() + 1 << endl << numeric_limits<int>::min() - 1 << endl;
    // max + 1 = min, min - 1 = max. This is C++ overflow
    int x = 2'000'000'000;
    int y = 1'000'000'000;
    cout << (x + y) / 2 << endl; // overflow - intermediate result is not in range
    unsigned int z = -x;
    cout << z << endl; // incorrect conversion;
    int a = -5;
    unsigned int b = 3;
    cout << a / b << endl; // when signed / unsigned, casted to UNSIGNED!!
    // logical - as unsigned also can not be correctly casted to signed as there is not enough bits
    // int / size_t -> size_t
    // int_32t + int8_t -> int32_t (int)
    // int8_t * uint8_t -> int
    a = numeric_limits<int8_t>::max();
    b = a;
    cout << a << ' ' << a  * b << endl;
    // how to debug this?
    // cout << a / b + vector<int>{}; // in error message, we see the operand result type
    int xx = -1;
    unsigned yy = 1u; // suffix u-> unsigned
    cout << (xx < yy) << endl; // x is casted to unsigned -> greater than 1
    return 0;
}
