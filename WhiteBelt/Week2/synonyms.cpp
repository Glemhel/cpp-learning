//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<string, set<string>> synonyms;
    for (int i = 0; i < q; i++) {
        string tt;
        cin >> tt;
        if (tt == "ADD") {
            string w1, w2;
            cin >> w1 >> w2;
            synonyms[w1].insert(w2);
            synonyms[w2].insert(w1);
        }
        if (tt == "COUNT") {
            string w;
            cin >> w;
            cout << synonyms[w].size() << endl;
        }
        if (tt == "CHECK") {
            string w1, w2;
            cin >> w1 >> w2;
            if (synonyms[w1].count(w2) == 0){
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
