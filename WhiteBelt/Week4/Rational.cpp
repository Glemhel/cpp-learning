//
// Created by mikhail on 01.05.2021.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

// greatest common divisor for two numbers
int gcd(int x, int y) {
    x = abs(x);
    y = abs(y);
    while (x != 0 && y != 0) {
        if (x > y)
            x %= y;
        else
            y %= x;
    }
    return max(x, y);
}

// class for representing rational numbers
class Rational {
public:

    // default constructor - zero value
    Rational() {
        numerator = 0;
        denominator = 1;
    };

    // Parametrized constructor
    Rational(int x, int y) {
        if (y == 0){
            throw invalid_argument("Denominator can't be 0");
        }
        numerator = x;
        denominator = y;
        // only numerator < 0
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        int _gcd = gcd(numerator, denominator);
        numerator /= _gcd;
        denominator /= _gcd;
        // if ratio is 0, denominator is 1 by convention
        if (numerator == 0)
            denominator = 1;
    };

    // numerator getter
    int Numerator() const {
        return numerator;
    };

    // denominator getter
    int Denominator() const {
        return denominator;
    };

private:
    int numerator;
    int denominator;
};

// equality test - since simplified, simple comparison
bool operator==(const Rational &lhs, const Rational &rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// common addition of ratios
Rational operator+(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()};
}

// unary minus operator
Rational operator-(const Rational &lhs) {
    return {-lhs.Numerator(), lhs.Denominator()};
}

// binary minus - addition of lhs + (-rhs) - unary minus is in use to avoid code repetition
Rational operator-(const Rational &lhs, const Rational &rhs) {
    return lhs + (-rhs);
}

// multiplication of two ratios
Rational operator*(const Rational &lhs, const Rational &rhs) {
    return {lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()};
}

// division - multiply by inverse of rhs
Rational operator/(const Rational &lhs, const Rational &rhs) {
    if (rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

// input operator with error-detection
istream &operator>>(istream &stream, Rational &number) {
    int num, den;
    char c;
    if (stream) {
        stream >> num >> c >> den;
        if (stream) {
            if (c == '/')
                number = Rational(num, den);
            else
                stream.setstate(ios_base::failbit);
        }
    }
    //cout << stream.fail() << endl;
    return stream;
}

// output operator
ostream &operator<<(ostream &stream, const Rational &number) {
    stream << number.Numerator() << "/" << number.Denominator();
    return stream;
}

// comparison - difference should be < 0 for lhs < rhs
bool operator<(const Rational &lhs, const Rational &rhs) {
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}