/**
 * Given the root of a binary search tree with distinct values, 
 * modify it so that every node has a new value equal to the sum of the 
 * values of the original tree that are greater than or equal to node.val
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int calculateLeft(TreeNode* root, int root_val) {
    
    if (root == nullptr || root->right == nullptr) return root_val; 
    while (root->right != nullptr) {
        root = root->right;
    }
    root->val += root_val;
    return 0;
}

int sum(TreeNode* root) {
    if (root == nullptr)  return 0; 
  
    int right_sum = sum(root->right); 

    root->val += right_sum;

    int leftCalculated = calculateLeft(root->left, root->val);

    if (root->left != nullptr) {
        root->left->val += leftCalculated;
    }

    int left_sum = sum(root->left);

    if (root->left != nullptr) {
        return left_sum;
    }
    return root->val;
}

TreeNode* bstToGst(TreeNode* root) {
    sum(root);
    return root;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printBinaryTree(root);
        printBinaryTree(bstToGst(root));
    }
    return 0;
}