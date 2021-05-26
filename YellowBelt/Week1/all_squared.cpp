//
// Created by mikhail on 26.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;
// containers output
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

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &pair);

template<typename T>
vector<T> Sqr(const vector<T> &v);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &m);

template<typename T>
T Sqr(const T &x);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair <First, Second> &pair) {
    return {Sqr(pair.first), Sqr(pair.second)};
}

template<typename T>
T Sqr(const T &x) {
    return x * x;
}

template<typename T>
vector<T> Sqr(const vector<T> &v) {
    auto new_v = v;
    for (auto &x: new_v)
        x = Sqr(x);
    return new_v;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &m) {
    auto new_m = m;
    for (auto &[key, value]: new_m) {
        value = Sqr(value);
    }
    return new_m;
}


int main() {
// Пример вызова функции
    vector<map<int, pair<int,int>>> a = {{{1, {2, 3}}}, {{5, {6, 7}}}};
    for (auto &x: Sqr(a))
        cout << x << endl;
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x: Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto &x: Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second <<
             endl;
    }
    return 0;
}
