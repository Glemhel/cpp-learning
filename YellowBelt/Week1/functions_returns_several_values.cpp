//
// Created by mikhail on 25.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Cities {
public:
    // returning several value with tuple
    tuple<bool, string> FindCountry(const string &city) const {
        if(city_to_country.count(city) == 1){
            // city_to_country[city] discards qualifiers = may be not const method of a class
            return {true, city_to_country.at(city)};
        } else if (ambiguous_cities.count(city) == 1) {
            return {false, "ambiguous"};
        } else{
            return {false, "does not exist"};
        }
    }

private:
    map<string, string> city_to_country;
    set<string> ambiguous_cities;
};

int main() {
    Cities cities;
    bool success;
    string message;
    auto t = cities.FindCountry("Volgograd");
    // more convenient way - bound variables
    tie(success, message) = cities.FindCountry("Volgograd");
    // another problem - 3 lines of code to declare this
    // structured bindings on their way
    auto [suc, mes] = cities.FindCountry("AAA");
    cout << suc << " " << mes << endl;
    cout << get<1>(t) << endl;
    cout << success << " " << message << endl;
    return 0;
}
