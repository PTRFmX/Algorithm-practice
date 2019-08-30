/**
 * Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].
 * After this process, we have some array B.
 * Return the smallest possible difference between the maximum value of B and the minimum value of B.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int smallestRangeI(vector<int>& A, int K) {
    int smallest = INT_MAX, largest = INT_MIN;
    for (int a : A) {
        if (a < smallest) {
            smallest = a;
        }
        if (a > largest) {
            largest = a;
        }
    }

    int dif = largest - smallest - 2 * K;

    return (dif >= 0 ? dif : 0);
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
        cout << smallestRangeI(A, K) << endl;
    }
    return 0;
}