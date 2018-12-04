/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int theShorter;
                if(height[i] >= height[j]) {
                    theShorter = height[j];
                }
                else {
                    theShorter = height[i];
                }

                if(theShorter * (j - i) > maxArea) {
                    maxArea = theShorter * (j - i);   
                }
                else{
                    continue;
                }
            }
        }
        return maxArea;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    vector<int> v;
    while(cin >> n) {
        v.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }
    Solution solution;
    cout << solution.maxArea(v) << endl;
    system("pause");
    return 0;
}