//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<string, string> countries;
    for (int i = 0; i < q; i++) {
        string tt;
        cin >> tt;
        if (tt == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (countries.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital "
                     << new_capital << endl;
            } else {
                if (countries[country] == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    const auto &old_capital = countries[country];
                    cout << "Country " << country << " has changed its capital from " << old_capital <<
                         " to " << new_capital << endl;
                }
            }
            countries[country] = new_capital;
        }
        if (tt == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (countries.count(old_country_name) == 0 || countries.count(new_country_name) != 0 ||
                old_country_name == new_country_name) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                auto capital = countries[old_country_name];
                countries.erase(old_country_name);
                countries[new_country_name] = capital;
                cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to "
                     << new_country_name << endl;
            }
        }
        if (tt == "ABOUT") {
            string country;
            cin >> country;
            if (countries.count(country) == 0){
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                const auto& capital = countries[country];
                cout << "Country " << country << " has capital " << capital << endl;
            }
        }
        if (tt == "DUMP") {
            if (countries.empty()){
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto &x: countries) {
                    cout << x.first << "/" << x.second << " ";
                }
                cout << endl;
            }
        }
    }
}