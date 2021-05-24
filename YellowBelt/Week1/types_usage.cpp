//
// Created by mikhail on 24.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    vector<int> x;
    //for (int i = 0; i < x.size(); i++) // problem - comparison of signed and unsigned
    //    cout << i << " " << x[i] << endl;
    // solution 1
    for (size_t i = 0; i < x.size(); i++){
        cout << i << " " << x[i] << endl;
    }
    // solution 2 - static cast
    for (int i = 0; i < static_cast<int>(x.size()); i++){
        cout << i << " " << x[i] << endl;
    }
    // all elements except last - (0u - 1) is large -> error. Better to i + 1 < x.size()
    for (size_t i = 0; i < x.size(); i++){
        cout << i << " " << x[i] << endl;
    }
    return 0;
}
