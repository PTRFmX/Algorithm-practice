/**
 * Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

bool isNode(TreeNode* root) {
    if (root == nullptr) {
        return false;
    }
    return (root->left == nullptr && root->right == nullptr);
}

int getTreeHeight(TreeNode* root, int depth = 0) {
    if (root == nullptr) {
        if (depth == 0) {
            return -1;
        }
        return depth;
    }
    int left = depth, right = depth;
    if (root->left != nullptr) {
        left = getTreeHeight(root->left, depth + 1);
    }
    if (root->right != nullptr) {
        right = getTreeHeight(root->right, depth + 1);
    }
    return (left > right ? left : right);
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (isNode(root)) {
        return root;
    }

    int left_height = getTreeHeight(root->left);
    int right_height = getTreeHeight(root->right);
    if (left_height == right_height) {
        return root;
    }
    else if (left_height > right_height) {
        return lcaDeepestLeaves(root->left);
    }
    else {
        return lcaDeepestLeaves(root->right);
    }
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printBinaryTree(lcaDeepestLeaves(root));
    }
    return 0;
}