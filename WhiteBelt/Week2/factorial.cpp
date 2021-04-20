//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>

using namespace std;

int Factorial(int x){
    int ans = 1;
    for (int i = 2; i <= x; i++){
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << Factorial(n);
}