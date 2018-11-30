/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
 * It doesn't matter what values are set beyond the returned length.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                i--;
            }       
        }
        return nums.size();
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
    cout << solution.removeDuplicates(v) << endl;
    system("pause");
    return 0;
}