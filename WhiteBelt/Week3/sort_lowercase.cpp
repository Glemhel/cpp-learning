//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string tolower(const string& s){
    string ans = s;
    for (auto& c: ans){
        c = tolower(c);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x: a)
        cin >> x;
    sort(begin(a), end(a),
         [](const string &a, const string &b) {
             return tolower(a) < tolower(b);
         });
    for (auto &x: a)
        cout << x << " ";
    return 0;
}
