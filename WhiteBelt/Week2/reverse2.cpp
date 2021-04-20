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

vector<int> Reversed(const vector<int>& v) {
    vector<int> ans = v;
    Reverse(ans);
    return ans;
}

int main() {
    vector<int> numbers = {1, 2, 3};
    auto x = Reversed(numbers);
    for (auto q: x)
        cout << q << " ";
}
