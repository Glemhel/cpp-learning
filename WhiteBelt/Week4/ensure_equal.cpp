//
// Created by mikhail on 02.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void EnsureEqual(const string &left, const string &right) {
    if (left != right) {
        ostringstream stream;
        stream << left << " != " << right;
        throw runtime_error(stream.str());
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}