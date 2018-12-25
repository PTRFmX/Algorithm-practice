/**
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 * You need to merge them into a new binary tree. 
 * The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t2 == nullptr) {
        return t1;
    }
    if(t1 == nullptr) {
        return t2;
    }
    TreeNode* t3 = new TreeNode(t1->val + t2->val);
    if(t1->left != nullptr || t2->left != nullptr) {
        t3->left = mergeTrees(t1->left, t2->left);
    }
    if(t1->right != nullptr || t2->right != nullptr) {
        t3->right = mergeTrees(t1->right, t2->right);
    }
    return t3;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* t1 = readBinaryTree();
        TreeNode* t2 = readBinaryTree();
        printBinaryTree(mergeTrees(t1, t2));
    }
    return 0;
}