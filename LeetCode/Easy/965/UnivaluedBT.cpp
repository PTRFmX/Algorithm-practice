/**
 * A binary tree is univalued if every node in the tree has the same value.
 * Return true if and only if the given tree is univalued.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

bool isUnivalTree(TreeNode* root) {
    bool isUnival = true;
    
    if(root->left != nullptr) {
        if(root->val != root->left->val) {
            return false;
        }
        isUnival = isUnivalTree(root->left);
    }
    
    if(root->right != nullptr) {
        if(root->val != root->right->val) {
            return false;
        }
        isUnival = isUnival && isUnivalTree(root->right);
    }

    return isUnival;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        cout << isUnivalTree(root) << endl;
    }
    return 0;
}