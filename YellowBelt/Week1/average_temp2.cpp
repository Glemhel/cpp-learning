//
// Created by mikhail on 24.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n; // max 1e6
    cin >> n;
    vector<int> v(n);
    for (auto &x: v)
        cin >> x; // max |1e8|
    int64_t sum = 0; // max 1e14 - 64 bits
    for (auto &x: v)
        sum += x;
    int avg = sum / n; // max |1e8|
    int cnt = 0; // max 1e6
    for (auto &x: v)
        if (x > avg)
            cnt++;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) // n is int, as well as i
        if (v[i] > avg)
            cout << i << " " ;
    return 0;
}
