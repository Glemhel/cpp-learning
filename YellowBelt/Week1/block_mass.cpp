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
    int n;
    uint64_t r;
    cin >> n >> r; // if r is uint8_t then reading works as reading symbol! very weird!
    // solution - read just int or overload input operator
    uint64_t sum_mass = 0;
    for (int i = 0; i < n; i++) {
        uint64_t w, h, d;
        cin >> w >> h >> d;
        sum_mass +=  w * h * d;
    }
    cout << sum_mass * static_cast<uint64_t>(r);
    return 0;
}
