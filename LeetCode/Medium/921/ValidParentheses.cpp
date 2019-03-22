/**
 * Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 * Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
*/
#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include "stdio.h" 

using namespace std;

int minAddToMakeValid(string S) {
    int index = 0, pos_index = 0, neg_index = 0;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == '(' && index >= 0) {
            index++;
        }
        else if(S[i] == '(' && index < 0) {
            pos_index++;
        }
        else if(S[i] == ')' && index > 0) {
            index--;
        }
        else if(S[i] == ')' && index <= 0) {
            neg_index++;
        }
    }
    // cout << index << " " << pos_index << " " << neg_index << endl;
    return index + pos_index + neg_index;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = readString();
        cout << minAddToMakeValid(s) << endl;
    }
    return 0;
}