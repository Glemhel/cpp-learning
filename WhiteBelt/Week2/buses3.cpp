//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<set<string>, int> buses;
    int bus_number = 1;
    while (q--) {
        int n;
        cin >> n;
        set<string> bus;
        for (int i = 0; i < n; i++){
            string stop;
            cin >> stop;
            bus.insert(stop);
        }
        if (buses.count(bus) != 0) {
            cout << "Already exists for " << buses[bus] << endl;
        } else {
            buses[bus] = bus_number;
            cout << "New bus " << bus_number++ << endl;
        }
    }
    return 0;
}
