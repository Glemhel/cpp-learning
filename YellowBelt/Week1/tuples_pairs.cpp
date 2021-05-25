//
// Created by mikhail on 25.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;

int main() {
    tuple<int, string, bool> t(7, "c++", true);
    //auto tt = tie(7, "c++", true); // auto uses reference, but we provide consts - error
    // method to avoid type definition - make_tuple
    // C++17 is able to avoid type definitons - it understands
    auto r = make_tuple(17, "C++", true);
    // tuple get operator is weird - using structs is better
    cout << get<1>(t) << get<0>(r) << endl;

    // easy usage of tuple with 2 args - pair!
    pair<int, string> a(9, "hello");
    // c++17 way without parameters
    pair aa(9, "hello");
    // old way without parameters
    auto b = make_pair(10, "hi");
    cout << a.first << " " << b.second << " " << aa.second << endl;

    // usage of pairs in maps
    map<int, string> digits = {{1, "one"}};
    for (const auto &item: digits) {
        cout << item.first << " " << item.second << endl;
    }
    // c++17 way - structured  bindings
    for (const auto&[key, value] : digits) {
        cout << key << " " << value << endl;
    }
    return 0;
}
