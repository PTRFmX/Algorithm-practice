/**
 * Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST.
 * Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 * Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root->val < val && root->right != nullptr) {
        root->right = insertIntoBST(root->right, val);
    }
    if(root->right == nullptr && root->val < val) {
        root->right = new TreeNode(val);
    }
    if(root->val > val && root->left != nullptr) {
        root->left = insertIntoBST(root->left, val);
    }
    if(root->left == nullptr && root->val > val) {
        root->left = new TreeNode(val);
    }
    if(root->left == nullptr && root->right == nullptr) {
        TreeNode* newNode = new TreeNode(val);
        if(root->val > val) {
            root->left = newNode;
        }
        if(root->val < val) {
            root->right = newNode;
        }
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
        printBinaryTree(insertIntoBST(root, val));
    }
    return 0;
}