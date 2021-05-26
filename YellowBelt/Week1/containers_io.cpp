//
// Created by mikhail on 26.05.2021.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <string>

using namespace std;

// template collection output to stream
template<typename Collection>
string Join(const Collection& c, char d){
    stringstream ss;
    bool first = true;
    for (const auto& item: c){
        if (!first)
            ss << d;
        ss << item;
        first = false;
    }
    return ss.str();
}

// template pair output
template<typename First, typename Second>
ostream &operator<<(ostream &ostream1, const pair<First, Second> &v) {
    return ostream1 << '(' << v.first << "," << v.second << ')';
}

// template vector output
template<typename T>
ostream &operator<<(ostream &ostream1, const vector<T> &v) {
    return ostream1 << "[" << Join(v, ',') << "]";
}

// template map output
template<typename Key, typename Value>
ostream &operator<<(ostream &ostream1, const map<Key, Value> &m) {
    return ostream1 << "{" <<  Join(m, ',') << "}";
}


int main() {
    vector<vector<int>> vi = {{1, 2}, {2, 3}, {4, 5}};
    cout << vi << endl;
    map<int, double> m = {{1, 2.5},
                          {3, 4}};
    cout << m;
    return 0;
}
