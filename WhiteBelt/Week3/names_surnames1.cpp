//
// Created by mikhail on 21.04.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

string FindNameByYear(const map<int, string>& history, const int& year){
    string name;
    for (const auto &item: history){
        if (item.first <= year)
            name = item.second;
        else
            break;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        // добавить факт изменения имени на first_name в год year
        first_name_history[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        // добавить факт изменения фамилии на last_name в год year
        last_name_history[year] = last_name;
    }

    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string first_name = FindNameByYear(first_name_history, year);
        string last_name = FindNameByYear(last_name_history, year);
        if (first_name.empty() && last_name.empty()){
            return "Incognito";
        }
        if (first_name.empty()){
            return last_name + " with unknown first name";
        }
        if (last_name.empty()){
            return first_name + " with unknown last name";
        }
        return first_name + " " + last_name;
    }

private:
    // приватные поля
    map<int, string> first_name_history;
    map<int, string> last_name_history;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

