//
// Created by mikhail on 26.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;


// template vector output
template<typename T>
ostream &operator<<(ostream &ostream1, const vector<T> &v) {
    for (const auto &i: v)
        ostream1 << i << " ";
    return ostream1;
}

// template pair output
template<typename First, typename Second>
ostream &operator<<(ostream &ostream1, const pair<First, Second> &v) {
    ostream1 << v.first << "," << v.second;
    return ostream1;
}

// template map output
template<typename Key, typename Value>
ostream &operator<<(ostream &ostream1, const map<Key, Value> &m) {
    for (const auto &i: m)
        ostream1 << i << " ";
    return ostream1;
}


int main() {
    vector<double> vi = {1, 2.4, 3};
    cout << vi << endl;
    map<int, double> m = {{1, 2.5},
                          {3, 4}};
    cout << m;
    return 0;
}
