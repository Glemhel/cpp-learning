//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if (!(a == 0 && b == 0)){
        if (a == 0){
            // linear equation
            double root = - c / b;
            cout << root;
        } else {
            // quadratic equation
            double det = b * b - 4 * a * c;
            if (det >= 0) {
                double root1 = (-b + sqrt(det)) / (2 * a);
                double root2 = (-b - sqrt(det)) / (2 * a);
                cout << root1;
                if (det != 0) {
                    cout << " " << root2;
                }
            }
        }
    }
    return 0;
}