//
// Created by mikhail on 23.04.2021.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFile(const string& path){
    ifstream input(path);
    if (input){
        string s;
        while (getline(input, s)){
            cout << s << endl;
        }
    } else {
        cout << "No such file" << endl;
    }
}

int main() {
    string path = "input.txt";
    PrintFile(path);
    return 0;
}
