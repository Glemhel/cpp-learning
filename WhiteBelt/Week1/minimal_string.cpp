//
// Created by mikhail on 20.04.2021.
//
#include <string>
#include <iostream>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c){
        cout << a;
    } else {
        if (b <= a && b <= c){
            cout << b;
        } else
            cout << c;
    }
    return 0;
}