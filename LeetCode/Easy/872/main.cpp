/**
 * Consider all the leaves of a binary tree.
 * From left to right order, the values of those leaves form a leaf value sequence.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> getTreeLeaf(TreeNode* root, vector<int> result = {}) {
    if (root->left == nullptr && root->right == nullptr) {
        result.push_back(root->val);
        return result;
    }
    if (root->left != nullptr) {
        result = getTreeLeaf(root->left, result);
    }
    if (root->right != nullptr) {
        result = getTreeLeaf(root->right, result);
    }
    return result;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    return getTreeLeaf(root1) == getTreeLeaf(root2);
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printVector(getTreeLeaf(root));
    }
    return 0;
}