//
// Created by mikhail on 26.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value> &m, const Key &key){
    if (m.count(key) == 0){
        throw runtime_error("");
    } else {
        return m[key];
    }
}


int main() {
    map<int, string> m = {{1, "value"}};
    string &item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}
