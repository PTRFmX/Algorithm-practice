/**
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 * Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

bool compareValue(int* c, int* n, int w, int h, vector<vector<int>>& matrix) {
    if (*c >= h || *n >= h || *(c + 1) >= w || *(n + 1) >= w) {
        return true;
    }
    return matrix[*c][*(c + 1)] == matrix[*n][*(n + 1)];
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {

    int h = matrix.size(), w = matrix[0].size();
    int bound = min(h, w), index_w = 0, index_h = 1;

    while(index_w < w) {
        for (int i = 0; i < bound; i++) {
            int current_diag[2] = {i, i + index_w};
            int next_diag[2] = {i + 1, i + index_w + 1};
            int* c = current_diag;
            int* n = next_diag;
            if (!compareValue(c, n, w, h, matrix)) {         
                return false;
            }
        }
        index_w++;
    }

    while(index_h < h) {
        for (int i = 0; i < bound; i++) {
            int current_diag[2] = {i + index_h, i};
            int next_diag[2] = {i + index_h + 1, i + 1};
            int* c = current_diag;
            int* n = next_diag;
            if (!compareValue(c, n, w, h, matrix)) {         
                return false;
            }
        }
        index_h++;
    }

    return true;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int w = readNumber();
        int h = readNumber();
        vector<vector<int>> matrix = readGrid(w, h);
        printGrid(matrix);
        cout << isToeplitzMatrix(matrix) << endl;        
    }
    return 0;
}