//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m) {
    set<string> ans;
    for (auto &item: m) {
        ans.insert(item.second);
    }
    return ans;
}

int main() {
    set<string> values = BuildMapValuesSet({
                                                   {1, "odd"},
                                                   {2, "even"},
                                                   {3, "odd"},
                                                   {4, "even"},
                                                   {5, "odd"}
                                           });

    for (const string &value : values) {
        cout << value << endl;
    }
    return 0;
}
