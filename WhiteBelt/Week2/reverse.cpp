//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void Reverse(vector<int> &v) {
    for (int i = 0; i < v.size() / 2; i++) {
        swap(v[i], v[v.size() - i - 1]);
    }
}

int main() {
    vector<int> numbers = {1, 2};
    Reverse(numbers);
    for (auto x: numbers)
        cout << x << " ";
}
