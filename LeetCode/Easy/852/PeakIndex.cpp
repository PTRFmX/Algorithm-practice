/**
 * Let's call an array A a mountain if the following properties hold:
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
 * Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
    int index = -1;
    int peak = A[0];
    for(int i = 1; i < A.size(); i++) {
        if(A[i] > peak) {
            peak = A[i];
            index = i;
        }
    }
    return index;
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
        cout << peakIndexInMountainArray(A) << endl;
    }
    return 0;
}