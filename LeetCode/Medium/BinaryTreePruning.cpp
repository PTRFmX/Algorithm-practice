/**
 * We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
 * Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
 * (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include "stdio.h" 

using namespace std;

TreeNode* pruneTree(TreeNode* root) {
    if(root->left != nullptr) {
        root->left = pruneTree(root->left);
    }
    if(root->right != nullptr) {
        root->right = pruneTree(root->right);
    }
    if(root->left == nullptr && root->right == nullptr && root->val == 0) {
        root = nullptr;
    }
    return root;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    TreeNode* result;
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        result = pruneTree(root);
        printBinaryTree(result);
    }
    return 0;
}