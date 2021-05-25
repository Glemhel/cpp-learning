//
// Created by mikhail on 25.05.2021.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool operator<(const Date &lhs, const Date &rhs) {
    /*
     naive solution - field-wise comparison
     cool solution - vector comparison
     problem - such usage of vector is overshoot - we need just to group values
     moreover, types of vector elements should be the same
     */
    // return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
    // solution with grouping into tuple
    // testing tie
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    // int a = 5 + lhs_key; // test - what lhs_key type is? answer: tuple<const int&, const int&, const int&>
                            // hence - no copying and straight access to elements
    return lhs_key < rhs_key;
}

int main() {
    cout << (Date{2017, 1, 10} < Date{2017,2,20}) << endl;
    return 0;
}
