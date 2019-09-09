/**
 * We have an array A of integers, and an array queries of queries.
 * For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index]. 
 * Then, the answer to the i-th query is the sum of the even values of A.
 * (Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)
 * Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> result;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        int original = A[queries[i][1]];
        A[queries[i][1]] += queries[i][0];
        if (A[queries[i][1]] % 2 == 0) {
            sum += A[queries[i][1]];
            if (original % 2 == 0) {
                sum -= original;
            }
        }
        else if (original % 2 == 0) {
            sum -= original;
        }
        result.push_back(sum);
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
        int n = readNumber();
        vector<vector<int>> queries = readGrid(n, 2);
        printVector(sumEvenAfterQueries(A, queries));
    }
    return 0;
}