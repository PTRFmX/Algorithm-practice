/**
 * S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
 * S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted.
 * More specifically, if x occurs before y in S, then x should occur before y in the returned string.
 * Return any permutation of T (as a string) that satisfies this property.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

string customSortString(string S, string T) {
    string result = S;
    for (char c : S) {
        int count = -1;
        while (T.find(c) != string::npos) {
            T.erase(T.find(c), 1);
            count++;
        }
        if (count < 0) {
            result.erase(result.find(c), 1);
        }
        for (int i = 0; i < count; i++) {
            result.insert(result.find(c), 1, c);
        }
    }

    return result + T;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = readString();
        string t = readString();
        cout << customSortString(s, t) << endl;
    }
    return 0;
}