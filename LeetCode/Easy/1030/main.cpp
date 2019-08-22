/**
 * We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.
 * Additionally, we are given a cell in that matrix with coordinates (r0, c0).
 * Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.
 * Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.
 * (You may return the answer in any order that satisfies this condition.)
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    int max_dis = R + C - 2;
    vector<vector<int>> result;
    for (int i = 0; i <= max_dis; i++) {
        for (int j = -i; j <= i; j++) {
            int col = c0 + j;
            if (col < 0 || col >= C) {
                continue;
            }
            if (r0 + i - abs(j) >= 0 && r0 + i - abs(j) < R) {
                result.push_back({r0 + i - abs(j), col});
            }
            if (r0 - i + abs(j) >= 0 && r0 - i + abs(j) < R && abs(j) != i) {
                result.push_back({r0 - i + abs(j), col});
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
        int R = readNumber();
        int C = readNumber();
        int r0 = readNumber();
        int c0 = readNumber();
        printGrid(allCellsDistOrder(R, C, r0, c0));
        cout << endl;
    }
    return 0;
}