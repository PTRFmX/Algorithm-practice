/**
 * We have a two dimensional matrix A where each value is 0 or 1.
 * A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
 * After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
 * Return the highest possible score.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int matrixScore(vector<vector<int>>& A) {
    for(int i = 0; i < A.size(); i++) {
        if(A[i][0] == 0) {
            for(int j = 0; j < A[i].size(); j++) {
                A[i][j] == 0 ? A[i][j] = 1 : A[i][j] = 0; 
            }
        }
    }
    for(int i = 0; i < A[0].size(); i++) {
        int count = 0;
        for(int j = 0; j < A.size(); j++) {
            if(A[j][i] == 0) {
                count++;
            }
        }
        if(count > A.size() / 2) {
            for(int j = 0; j < A.size(); j++) {
                A[j][i] == 0 ? A[j][i] = 1 : A[j][i] = 0;
            }
        }
    }

    int result = 0;

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            result += (A[i][j] == 0 ? 0 : pow(2, A[i].size() - 1 - j));
        }
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
        int inner_size = readNumber();
        vector<vector<int>> A = readGrid(size, inner_size);
        matrixScore(A);
    }
    return 0;
}