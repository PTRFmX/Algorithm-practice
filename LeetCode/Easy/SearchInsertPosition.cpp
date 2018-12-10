/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array. 
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums[nums.size() - 1]) {
            return nums.size();
        }
        else if(target <= nums[0]) {
            return 0;
        }
        int result;
        for(int i = 1; i < nums.size(); i++) {
            if((target > nums[i - 1] && target < nums[i]) || target == nums[i]) {
                result = i;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    vector<int> nums;
    while(cin >> n) {
        nums.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }

    int target;
    cin >> target;

    Solution solution;
    cout << solution.searchInsert(nums, target) << endl;
    system("pause");
    return 0;
}
