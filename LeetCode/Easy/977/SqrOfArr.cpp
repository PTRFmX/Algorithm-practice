/**
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    vector<int> sqrVec;
    for(int i = 0; i < A.size(); i++) {
        sqrVec.push_back(A[i] * A[i]);
    }
    sort(sqrVec.begin(), sqrVec.end());
    return sqrVec;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> A = readVector(size);
        printVector(sortedSquares(A));
    }
    return 0;
}