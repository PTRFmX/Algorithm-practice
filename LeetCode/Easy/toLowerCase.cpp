/**
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
*/


#include <iostream>
#include <vector>
#include <string>
#include "../headers/leetcode.h"

using namespace std;

string toLowerCase(string str) {
    string result;
    for(char s : str) {
        int num = s;
        char upper = num;
        if(num >= 65 && num <= 90) {
            upper += 32;
        }
        result += upper;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for(int i = 0; i < m; ++i) {
        string str = readString();
        cout << toLowerCase(str) << endl;
    }
    return 0;
}