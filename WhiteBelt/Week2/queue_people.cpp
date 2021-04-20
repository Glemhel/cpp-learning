//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> people;
    int q;
    cin >> q;
    for (int j = 0; j < q; j++){
        string s;
        cin >> s;
        if (s == "WORRY") {
            int x;
            cin >> x;
            people[x] = 1;
        }
        if (s == "QUIET") {
            int x;
            cin >> x;
            people[x] = 0;
        }
        if (s == "COME") {
            int k;
            cin >> k;
            people.resize(people.size() + k, 0);
        }
        if (s == "WORRY_COUNT") {
            int worry = count(begin(people), end(people), 1);
            cout << worry << endl;
        }
    }
    return 0;
}
