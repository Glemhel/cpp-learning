//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    int average = 0;
    for (int& x: t){
        cin >> x;
        average += x;
    }
    average /= n;
    vector<int> t_greater;
    for (int i = 0; i < n; i++){
        if (t[i] > average)
            t_greater.push_back(i);
    }
    cout << t_greater.size() << endl;
    for (const auto& x: t_greater)
        cout << x << " ";
}