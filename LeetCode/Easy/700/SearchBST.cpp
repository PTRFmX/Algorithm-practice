/**
 * Given the root node of a binary search tree (BST) and a value.
 * You need to find the node in the BST that the node's value equals the given value.
 * Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->val == val) {
        return root;
    }
    root->left = searchBST(root->left, val);
    if(root->left != nullptr) {
        root = root->left;
    }
    else {
        root = searchBST(root->right, val);
    }
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
        int val = readNumber();
        printBinaryTree(searchBST(root, val));
    }
    return 0;
}