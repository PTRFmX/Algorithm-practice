/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
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
    vector<int> nums;
    while(cin >> n) {
        nums.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }
    int val;
    cin >> val;
    Solution solution;
    cout << solution.removeElement(nums, val) << endl;
    system("pause");
    return 0;
}
