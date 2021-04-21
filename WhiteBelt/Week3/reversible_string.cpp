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

class ReversibleString {
public:

    ReversibleString() {}

    ReversibleString(const string &s) {
        str = s;
    }

    string ToString() const {
        return str;
    }

    void Reverse() {
        reverse(begin(str), end(str));
    }

private:
    string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}