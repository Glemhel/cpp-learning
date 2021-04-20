//
// Created by mikhail on 20.04.2021.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> ans;
    for (auto w: words) {
        if (IsPalindrom(w) && w.size() >= minLength)
            ans.push_back(w);
    }
    return ans;
}

int main() {
    vector<string> words = {"weew", "bro", "code"};
    int minLength = 4;
    auto ans = PalindromFilter(words, minLength);
    for (auto x: ans)
        cout << x << " ";
}