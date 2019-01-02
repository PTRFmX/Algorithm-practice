/**
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 * You may return any answer array that satisfies this condition.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> odd, even, result;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] % 2 != 0) {
            odd.push_back(A[i]);
        }
        else {
            even.push_back(A[i]);
        }
    }
    for(int i = 0; i < odd.size(); i++) {
        result.push_back(even[i]);
        result.push_back(odd[i]);
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
        int size = readNumber();
        vector<int> A = readVector(size);
        sortArrayByParityII(A);
    }
    return 0;
}