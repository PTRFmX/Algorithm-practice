/**
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.
*/

#include <iostream>
#include "../headers/leetcode.h"
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> result;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] % 2 == 0) {
            result.push_back(A[i]);
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i] % 2 != 0) {
            result.push_back(A[i]);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> A = readVector(size);
        sortArrayByParity(A);
    }
    return 0;
}