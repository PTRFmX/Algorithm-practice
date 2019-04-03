/**
 * Given a matrix A, return the transpose of A.
 * The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
    if (A.size() == 0) {
        return {};
    }
    vector<vector<int>> result;
    for (int i = 0; i < A[0].size(); i++) {
        vector<int> el;
        for (int j = 0; j < A.size(); j++) {
            el.push_back(A[j][i]);
        }
        result.push_back(el);
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
        int k = readNumber(), n = readNumber();
        vector<vector<int>> A = readGrid(k, n);
        printGrid(transpose(A));
    }
    return 0;
}