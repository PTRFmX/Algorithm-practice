/**
 * Given two strings representing two complex numbers.
 * You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

string complexNumberMultiply(string a, string b) {
    int a_add_pos = a.find('+'), b_add_pos = b.find('+');
    int a_1 = stoi(a.substr(0, a_add_pos)), a_2 = stoi(a.substr(a_add_pos + 1, a.length() - 2 - a_add_pos));
    int b_1 = stoi(b.substr(0, b_add_pos)), b_2 = stoi(b.substr(b_add_pos + 1, b.length() - 2 - b_add_pos));
    string result = to_string(a_1 * b_1 - a_2 * b_2) + "+" + to_string(a_1 * b_2 + a_2 * b_1) + "i";
    return result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string a = readString();
        string b = readString();
        cout << complexNumberMultiply(a, b) << endl;
    }
    return 0;
}