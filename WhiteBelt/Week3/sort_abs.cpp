//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int my_abs(const int &x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;
    sort(begin(a), end(a), [](int a, int b) {
        return my_abs(a) < my_abs(b);
    });
    for (const auto &x: a) {
        cout << x << " ";
    }
    return 0;
}
