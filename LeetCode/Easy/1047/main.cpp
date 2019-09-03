/**
 * Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
 * We repeatedly make duplicate removals on S until we no longer can.
 * Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int containsDuplicate(string S) {
    if (S.length() <= 1) {
        return -1;
    }
    for (int i = 0; i < S.length() - 1; i++) {
        if (S[i] == S[i + 1]) {
            return i;
        }
    }
    return -1;
}

string removeDuplicates(string S) {
    int pos = containsDuplicate(S);
    while(pos != -1) {
        S.erase(pos, 2);
        pos = containsDuplicate(S);
    }
    return S;
}


int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = readString();
        cout << removeDuplicates(s) << endl;
    }
    return 0;
}