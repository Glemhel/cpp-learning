//
// Created by mikhail on 25.04.2021.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int dayBirth;
    int monthBirth;
    int yearBirth;


};

int main() {
    //ifstream cin("C:\\Users\\yarud\\CppLearning\\WhiteBelt\\Week4\\cin.txt");
    //ofstream cout("C:\\Users\\yarud\\CppLearning\\WhiteBelt\\Week4\\cout.txt");
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        string name, surname;
        cin >> name >> surname;
        int day, month, year;
        cin >> day >> month >> year;
        Student x = {name, surname, day, month, year};
        students[i] = x;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string tt;
        int k;
        cin >> tt >> k;
        if (k < 1 || k > n || !(tt == "name" || tt == "date")) {
            cout << "bad request" << endl;
        } else {
            if (tt == "name") {
                cout << students[k - 1].firstName << " " << students[k - 1].lastName << endl;
            } else {
                cout << students[k - 1].dayBirth << "." << students[k - 1].monthBirth << "."
                     << students[k - 1].yearBirth << endl;
            }
        }
    }
    return 0;
}
