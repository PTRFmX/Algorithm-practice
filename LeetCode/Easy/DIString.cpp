/**
 * Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
 * Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
 * If S[i] == "I", then A[i] < A[i+1]
 * If S[i] == "D", then A[i] > A[i+1]
*/

#include "../headers/leetcode.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector<int> diStringMatch(string S) {
    vector<int> result;
    int count_I = 0, count_D = 0;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == 'I') {
            result.push_back(count_I);
            count_I++;
        }
        else if(S[i] == 'D') {
            result.push_back(S.length() - count_D);
            count_D++;
        }
    }
    result.push_back(count_I);
    return result;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string S = readString();
        diStringMatch(S);
    }
    return 0;
}