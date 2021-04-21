//
// Created by mikhail on 21.04.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>


using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(strings), end(strings));
        return strings;
    }
private:
    vector<string> strings;
};


int main() {

    return 0;
}
