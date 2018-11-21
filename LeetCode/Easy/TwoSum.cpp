/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, target;
    vector<int> v;
    while(cin >> n) {
        v.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }
    cin >> target;
    Solution solution;
    vector<int> result = solution.twoSum(v, target);
    cout << "The indices are: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}