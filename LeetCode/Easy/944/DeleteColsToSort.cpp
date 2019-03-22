/**
 * We are given an array A of N lowercase letter strings, all of the same length.
 * Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.
 * For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"], and the remaining columns of A are ["b","v"], ["e","y"], and ["f","z"].  (Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]].)
 * Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.
 * Return the minimum possible value of D.length.
*/


#include "../headers/leetcode.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& A) {
    set<int> delNums;
    for(int i = 0; i < A.size() - 1; i++) {
        for(int j = 0; j < A[i].length(); j++) {
            if(A[i][j] > A[i + 1][j] ) {
                delNums.insert(j);
            }
        }
    }
    return delNums.size();
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<string> A = readStringVector(size);
        cout << minDeletionSize(A) << endl;
    }
    return 0;
}