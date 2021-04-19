//
// Created by mikhail on 20.04.2021.
//

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0){
        cout << "Impossible";
    } else {
        cout << a / b;
    }
    return 0;
}
