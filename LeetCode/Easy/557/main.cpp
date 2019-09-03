/**
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

string reverseSingleWord(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        char temp = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = temp;
    }
    return s;
}

string reverseWords(string s) {
    string result;
    while(s.find(' ') != string::npos){
        int pos = s.find(' ');
        result += reverseSingleWord(s.substr(0, pos)) + ' ';
        s = s.substr(pos + 1, s.length() - pos - 1);
    }
    result += reverseSingleWord(s);
    return result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        cin.ignore();
        string s = readStringLine();
        cout << reverseWords(s) << endl;
    }
    return 0;
}