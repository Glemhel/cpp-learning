#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
#include <sstream>

using namespace std;

bool PeekAndSkip(istringstream &s) {
    if (s.peek() != '-')
        return false;
    s.ignore(1);
    return true;
}

void PeekOrThrow(istringstream &s, const string &error) {
    if (!PeekAndSkip(s))
        throw domain_error(error);
}

class Date {
public:

    Date() {}

    explicit Date(const string &date) {
        istringstream s(date);
        string error = "Wrong date format: " + date;
        int new_year, new_month, new_day;
        if (!s)
            throw domain_error(error);
        s >> new_year;
        if (!s)
            throw domain_error(error);
        PeekOrThrow(s, error);
        s >> new_month;
        if (!s)
            throw domain_error(error);
        PeekOrThrow(s, error);
        s >> new_day;
        if (s.eof() && !s.fail()) {
            year = new_year;
            month = new_month;
            day = new_day;
        } else {
            throw domain_error(error);
        }
        if (!(1 <= month && month <= 12))
            throw domain_error("Month value is invalid: " + to_string(month));
        if (!(1 <= day && day <= 31))
            throw domain_error("Day value is invalid: " + to_string(day));
    }

    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

istream &operator>>(istream &istream1, Date &date) {
    string s;
    istream1 >> s;
    date = Date(s);
    return istream1;
}

ostream &operator<<(ostream &ostream1, const Date &date) {
    ostream1 << setw(4) << setfill('0') << date.GetYear() << "-" <<
             setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
    return ostream1;
}

class Database {
public:
    void AddEvent(const Date &date, const string &event) {
        if (!event.empty())
            date_events[date].insert(event);
    }

    bool DeleteEvent(const Date &date, const string &event) {
        if (date_events[date].count(event) != 0) {
            date_events[date].erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date &date) {
        int deleted = date_events[date].size();
        date_events[date].clear();
        return deleted;
    }

    vector<string> Find(const Date &date) const {
        if (date_events.count(date) > 0)
            return {begin(date_events.at(date)), end(date_events.at(date))};
        return {};
    }

    void Print() const {
        for (const auto &kvp: date_events) {
            for (const auto &event: kvp.second) {
                cout << kvp.first << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> date_events;
};

int main() {
    Database db;

    string command;
    try {
        while (getline(cin, command)) {
            if (command.empty())
                continue;
            istringstream cmd(command);
            cmd >> command;
            if (command == "Add") {
                Date date;
                string event;
                cmd >> date >> event;
                db.AddEvent(date, event);
            } else if (command == "Del") {
                Date date;
                string event;
                cmd >> date >> event;
                if (event.empty()) {
                    int deleted = db.DeleteDate(date);
                    cout << "Deleted " << deleted << " events";
                } else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully";
                    } else {
                        cout << "Event not found";
                    }
                }
                cout << endl;
            } else if (command == "Find") {
                Date date;
                cmd >> date;
                for (const auto &event: db.Find(date)) {
                    cout << event << endl;
                }
            } else if (command == "Print") {
                db.Print();
            } else {
                if (!command.empty()) {
                    throw domain_error("Unknown command: " + command);
                }
            }
        }
    } catch (const domain_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}