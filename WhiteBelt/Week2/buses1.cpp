//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<string, vector<string>> buses_for_stop;
    map<string, vector<string>> stops_for_bus;
    for (int i = 0; i < q; i++) {
        string tt;
        cin >> tt;
        if (tt == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            vector<string> stops(stop_count);
            for (auto &stop : stops) {
                cin >> stop;
                buses_for_stop[stop].push_back(bus);
            }
            stops_for_bus[bus] = stops;
        }
        if (tt == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (buses_for_stop.count(stop) == 0) {
                cout << "No stop" << endl;
            } else {
                for (const auto &bus: buses_for_stop[stop]) {
                    cout << bus << " ";
                }
                cout << endl;
            }
        }
        if (tt == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (stops_for_bus.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const auto &stop: stops_for_bus[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (buses_for_stop[stop].size() == 1) {
                        cout << "no interchange" << endl;
                    } else {
                        for (const auto &bus_on_stop: buses_for_stop[stop]) {
                            if (bus_on_stop != bus) {
                                cout << bus_on_stop << " ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
        if (tt == "ALL_BUSES") {
            if (stops_for_bus.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto &item : stops_for_bus) {
                    cout << "Bus " << item.first << ": ";
                    for (const auto &stop: item.second) {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
