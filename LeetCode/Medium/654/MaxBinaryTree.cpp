/**
 * Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of this tree.
*/

#include "../headers/leetcode.h"
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(nums.size() == 0) {
        return nullptr;
    }
    int index = 0, biggest = nums[0];
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > biggest) {
            biggest = nums[i];
            index = i;
        }
    }

    vector<int> left, right;
    for(int i = 0; i < index; i++) {
        left.push_back(nums[i]);
    }
    for(int i = index + 1; i < nums.size(); i++) {
        right.push_back(nums[i]);
    }

    TreeNode *root = new TreeNode(biggest);
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
}


int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> nums = readVector(size);
        constructMaximumBinaryTree(nums);
    }
    return 0;
}