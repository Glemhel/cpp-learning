//
// Created by mikhail on 26.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

template<typename T>
T Max(T a, T b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    // we explicitly define type of arguments
    cout << max<double>(2, 3.5);
    return 0;
}
