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
    int x = 2'0'0'0'0; // convenient delimiter
    cout << x << endl;
    vector<int> t = {-8, -3, 1};
    int sum = 0;
    for (int i : t)
        sum += i;
    int avg = sum / t.size(); // error! division by unsigned
    cout << avg << endl;
    cout << sizeof(int16_t) << endl; // size of variable in bytes
    cout << numeric_limits<int>::min() << endl << numeric_limits<int>::max(); // limits
    return 0;
}
