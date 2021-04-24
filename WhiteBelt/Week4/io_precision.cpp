//
// Created by mikhail on 25.04.2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    double x;
    cout << fixed << setprecision(3);
    while (input >> x) {
        cout << x << endl;
    }
    return 0;
}
