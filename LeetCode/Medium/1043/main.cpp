/**
 * Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.
 * After partitioning, each subarray has their values changed to become the maximum value of that subarray.
 * Return the largest sum of the given array after partitioning.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

int maxSumAfterPartitioning(vector<int>& A, int K) {
    vector<int> result(A.size() + 1);
    for (int i = 0; i < A.size(); i++) {
        int m = A[i];
        for (int j = 0; j < K && (i + 1) - (j + 1) >= 0; j++) {
            m = max(m, A[i - j]);
            result[i + 1] = max(result[i + 1], result[(i + 1) - (j + 1)] + m * (j + 1));
        }
    }
    return result[A.size()];
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
        int K = readNumber();
        cout << maxSumAfterPartitioning(A, K) << endl;
    }
    return 0;
}