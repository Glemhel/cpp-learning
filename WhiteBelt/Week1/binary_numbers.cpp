//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num;
    while (n > 0){
        num.push_back(n % 2);
        n /= 2;
    }
    for (int i = num.size() - 1; i >= 0; i--){
        cout << num[i];
    }
}