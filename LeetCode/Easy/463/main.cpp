/**
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally). 
 * The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
 * The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
 * One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
 * Determine the perimeter of the island.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

int getSinglePerimeter(vector<vector<int>>& grid, int row, int col) {
    int perimeter = 4;
    if (row - 1 >= 0 && grid[row - 1][col]) {
        perimeter--;
    }
    if (row + 1 < grid.size() && grid[row + 1][col]) {
        perimeter--;
    }
    if (col - 1 >= 0 && grid[row][col - 1]) {
        perimeter--;
    }
    if (col + 1 < grid[0].size() && grid[row][col + 1]) {
        perimeter--;
    }
    return perimeter;
}
    
int islandPerimeter(vector<vector<int>>& grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j]) {
                result += getSinglePerimeter(grid, i, j);
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
        
    }
    return 0;
}
