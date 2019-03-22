/**
 * A string S of lowercase letters is given. 
 * We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> partitionLabels(string S) {
    int index = 0, anchor = 0;
    int char_set[26];
    vector<int> result;
    for(int i = 0; i < S.length(); i++) {
        char_set[S[i] - 'a'] = i;
    }
    for(int i = 0; i < S.length(); i++) {
        index = max(index, char_set[S[i] - 'a']);
        if(i == index) {
            result.push_back(i + 1 - anchor);
            anchor = i + 1;
        }
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
        string S = readString();
        partitionLabels(S);
    }
    return 0;
}