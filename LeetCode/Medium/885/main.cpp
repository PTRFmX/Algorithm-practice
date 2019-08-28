/**
 * On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
 * Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.
 * Now, we walk in a clockwise spiral shape to visit every position in this grid. 
 * Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 
 * Eventually, we reach all R * C spaces of the grid.
 * Return a list of coordinates representing the positions of the grid in the order they were visited.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

bool isValid(int c0, int r0, int C, int R) {
    return c0 >= 0 && r0 >= 0 && c0 < C && r0 < R;
}

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> result = {{r0, c0}};
    int total_grid = R * C, step = 0;
    while(result.size() < total_grid) {
        step++;
        for (int i = 0; i < step; i++) {
            c0++;
            if (isValid(c0, r0, C, R)) {
               result.push_back({r0, c0}); 
            }
        }
        for (int i = 0; i < step; i++) {
            r0++;
            if (isValid(c0, r0, C, R)) {
                result.push_back({r0, c0});
            }
        }
        step++;
        for (int i = 0; i < step; i++) {
            c0--;
            if (isValid(c0, r0, C, R)) {
                result.push_back({r0, c0});
            }
        }
        for (int i = 0; i < step; i++) {
            r0--;
            if (isValid(c0, r0, C, R)) {
                result.push_back({r0, c0});
            }
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
        int R = readNumber(), C = readNumber(), r0 = readNumber(), c0 = readNumber();
        printGrid(spiralMatrixIII(R, C, r0, c0));
    }
    return 0;
}