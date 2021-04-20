//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
