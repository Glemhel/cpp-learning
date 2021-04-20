//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<vector<string>, int> buses;
    int bus_number = 1;
    while (q--) {
        int n;
        cin >> n;
        vector<string> stops(n);
        for (auto &stop: stops)
            cin >> stop;
        if (buses.count(stops) != 0) {
            cout << "Already exists for " << buses[stops] << endl;
        } else {
            buses[stops] = bus_number;
            cout << "New bus " << bus_number++ << endl;
        }
    }
    return 0;
}
