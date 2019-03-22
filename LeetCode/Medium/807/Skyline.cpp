/**
 * In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). 
 * Height 0 is considered to be a building as well. 
 * At the end, the "skyline" when viewed from all four directions of the grid
 * i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. 
 * A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. 
 * What is the maximum total sum that the height of the buildings can be increased?
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "../headers/leetcode.h"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> skylineHr, skylineVr;

        for(int i = 0; i < grid.size(); i++) {
            int temp_vr, temp_hr = 0;
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] > temp_vr) {
                    temp_vr = grid[i][j];
                }
                if(grid[j][i] > temp_hr) {
                    temp_hr = grid[j][i];
                }
            }
            skylineVr.push_back(temp_vr);
            skylineHr.push_back(temp_hr);
        }

        int sum = 0;
        for(int i = 0; i < skylineVr.size(); i++) {
            for(int j = 0; j < skylineHr.size(); j++) {
                int smaller = (skylineVr[i] > skylineHr[j]) ? skylineHr[j] : skylineVr[i];
                sum += smaller - grid[i][j];
            }
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    vector<vector<int>> grid;
    for(int i = 0; i < 4; i++) {
        vector<int> row;
        while(cin >> n) {
            row.push_back(n);
            if(getchar() == 'a') {
                break;
            }        
        }
        grid.push_back(row);
    }
    Solution solution;
    cout << solution.maxIncreaseKeepingSkyline(grid) << endl;
    system("pause");
    return 0;
}
