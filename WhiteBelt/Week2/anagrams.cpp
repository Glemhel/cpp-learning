//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildMap(const string& s){
    map<char, int> m;
    for (auto c: s){
        m[c]++;
    }
    return m;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        if (BuildMap(s) == BuildMap(t)){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}
