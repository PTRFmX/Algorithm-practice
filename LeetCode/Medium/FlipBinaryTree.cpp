/**
 * For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
 * Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if(root1 == root2) {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
        return false;
    }
    bool r1, r2;
    r1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    r2 = flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right);
    return r1||r2;
}

TreeNode* search(TreeNode* root) {
    
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root1 = readBinaryTree();
        TreeNode* root2 = readBinaryTree();
        cout << flipEquiv(root1, root2) << endl;
    }
    return 0;
}