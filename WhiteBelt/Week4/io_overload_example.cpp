//
// Created by mikhail on 01.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

istream &operator>>(istream &stream, Point &point) {
    stream >> point.x >> point.y;
}

ostream &operator<<(ostream &stream, const Point &point) {
    stream << point.x << " " << point.y;
}

Point operator+(const Point &lhs, const Point &rhs) {
    return Point{lhs.x + rhs.x, lhs.y + rhs.y};
}

bool operator<(const Point &lhs, const Point &rhs){
    if (lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

int main() {
    Point p{1, 2}, p1{2, 3}, p2{4, -1};
//    cin >> p;
//    cout << p << endl;
//    cout << p1;
//    operator>>(operator>>(cin, p1), p2); // Equivalent to
//    // cin >> p1 >> p2
    Point p12 = p1 + p2;
    cout << p12 << endl;
    vector<Point> v = {p1, p2, p};
    sort(begin(v), end(v));
    // sort with lambda function
//    sort(begin(v), end(v), [](const Point& a, const Point& b){
//        if (a.x != b.x)
//            return a.x < b.x;
//        return a.y < b.y;
//    });
    for (auto&x:v)
        cout << x << " ";
    return 0;
}
