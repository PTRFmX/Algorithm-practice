/**
 * Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> findAllPos(string S, char C) {
    vector<int> char_pos;
    int pos = S.find(C);
    while(pos != string::npos) {
        char_pos.push_back(char_pos.size() == 0 ? pos : pos + char_pos[char_pos.size() - 1] + 1);
        S = S.substr(pos + 1, S.length() - (pos + 1));
        pos = S.find(C);
    }
    return char_pos;
}

vector<int> shortestToChar(string S, char C) {
    vector<int> result;
    vector<int> char_pos = findAllPos(S, C);
    for (int i = 0; i < S.length(); i++) {
        int smallest = abs(char_pos[0] - i);
        for (int j = 1; j < char_pos.size(); j++) {
            int val = abs(char_pos[j] - i);
            if (val < smallest) {
                smallest = val;
            }
        }
        result.push_back(smallest);
    }
    return result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = readString();
        char c = readChar();
        printVector(shortestToChar(s, c));
    }
    return 0;
}