//
// Created by mikhail on 23.04.2021.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFile(const string &path_input, const string &path_output) {
    ifstream input(path_input);
    ofstream output(path_output);
    if (input && output) {
        string s;
        while (getline(input, s)) {
            output << s << endl;
        }
    } else {
        cout << "No such file" << endl;
    }
}

int main() {
    string path_input = "input.txt";
    string path_output = "output.txt";
    PrintFile(path_input, path_output);
    return 0;
}
