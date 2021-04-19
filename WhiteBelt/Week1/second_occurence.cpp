//
// Created by mikhail on 20.04.2021.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int first = -1;
    int second = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'f') {
            if (first == -1){
                first = i;
            } else {
                second = i;
                break;
            }
        }
    }
    if (first == -1) {
        cout << -2;
    } else {
        if (second == -1){
            cout << -1;
        } else {
            cout << second;
        }
    }
    return 0;
}
