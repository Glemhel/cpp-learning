//
// Created by mikhail on 21.04.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>

using namespace std;


vector<string> NameHistoryByYear(const map<int, string> &history, const int &year) {
    vector<string> names;
    for (const auto &item : history) {
        if (item.first <= year && (names.empty() || names.back() != item.second))
            names.push_back(item.second);
        else
            break;
    }
    return names;
}

string GenerateStringFromHistory(vector<string> history) {
    if (history.empty())
        return "";
    reverse(begin(history), end(history));
    string ans = history[0];
    if (history.size() > 1) {
        ans += " (";
        for (int i = 1; i < history.size(); i++) {
            if (i > 1)
                ans += ", ";
            ans += history[i];
        }
        ans += ")";
    }
    return ans;
}

string GenerateFullName(const string &first_name, const string &last_name) {
    if (first_name.empty() && last_name.empty()) {
        return "Incognito";
    }
    if (first_name.empty()) {
        return last_name + " with unknown first name";
    }
    if (last_name.empty()) {
        return first_name + " with unknown last name";
    }
    return first_name + " " + last_name;
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
        vector<string> first_names = NameHistoryByYear(first_name_history, year);
        vector<string> last_names = NameHistoryByYear(last_name_history, year);
        string first_name = (first_names.empty() ? "" : first_names.back());
        string last_name = (last_names.empty() ? "" : last_names.back());
        return GenerateFullName(first_name, last_name);
    }

    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        vector<string> first_names = NameHistoryByYear(first_name_history, year);
        vector<string> last_names = NameHistoryByYear(last_name_history, year);
        string first_name = GenerateStringFromHistory(first_names);
        string last_name = GenerateStringFromHistory(last_names);
        return GenerateFullName(first_name, last_name);
    }

private:
    // приватные поля
    map<int, string> first_name_history;
    map<int, string> last_name_history;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}