//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s){
    for (int i = 0; i < s.size(); i++){
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

int main() {
    string x;
    cin >> x;
    if (IsPalindrom(x))
        cout << "true";
    else
        cout << "false";
}