//
// Created by mikhail on 22.04.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization(const string& s) {
        value = s;
    }
};

struct Course {
    string value;

    explicit Course(const string& s) {
        value = s;
    }
};

struct Week {
    string value;

    explicit Week(const string& s) {
        value = s;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& s, const Course& c, const Week& w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

//    LectureTitle title(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );

    return 0;
}
