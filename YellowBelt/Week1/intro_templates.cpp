//
// Created by mikhail on 25.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

//
//int Sqr(int x) {
//    return x * x;
//}
//
//double Sqr(double x) {
//    return x * x;
//}

// code redundancy..
// templates!

template <typename First, typename Second>
pair<First, Second> operator* (const pair<First, Second> &lhs, const pair<First, Second> &rhs){
    First f = lhs.first * rhs.first;
    Second s = lhs.second * rhs.second;
    return make_pair(f, s);
}

template<typename T>
T Sqr(T x) {
    return x * x;
}

int main() {
    auto p = make_pair(2.5, 3);
    auto q = p * p;
    cout << q.first << " " << q.second;
    return 0;
}
