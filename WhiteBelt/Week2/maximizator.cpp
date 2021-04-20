//
// Created by mikhail on 20.04.2021.
//
#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second){
    if (first > second)
        second = first;
}
int main() {
    int a = 2, b = 3;
    UpdateIfGreater(a, b);
    cout << b;
}
