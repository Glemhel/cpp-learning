//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void assign_todo(vector<vector<string>> &todo, int day, const string &name) {
    todo[day].push_back(name);
}

void output_todo(const vector<vector<string>> &todo, int day) {
    cout << todo[day].size() << " ";
    for (auto &x: todo[day]) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    vector<int> day_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> todo(31);
    int month = 0;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "ADD") {
            int day;
            string name;
            cin >> day >> name;
            assign_todo(todo, day - 1, name);
        }
        if (s == "DUMP") {
            int day;
            cin >> day;
            output_todo(todo, day - 1);
        }
        if (s == "NEXT") {
            month = (month + 1) % 12;
            auto& last_day_todo = todo[day_in_months[month] - 1];
            if (day_in_months[month] < todo.size()) {
                for (int j = day_in_months[month]; j < todo.size(); j++) {
                    last_day_todo.insert(end(last_day_todo),
                                         begin(todo[j]),
                                         end(todo[j]));
                }
            }
            todo.resize(day_in_months[month]);
        }
    }
    return 0;
}
