/**
 * Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
 * and every node has no left child and only 1 right child.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void preOrderTraversal(TreeNode* root, vector<int>* result) {
    if (root == nullptr) {
        return;
    }
    preOrderTraversal(root->left, result);
    result->push_back(root->val);
    preOrderTraversal(root->right, result);
}

void toTree(vector<int>* v, TreeNode* root) {
    for (int i = 1; i < v->size(); i++) {
        TreeNode* node = new TreeNode(v->at(i));
        root->right = node;
        root = root->right;
    }
}

TreeNode* increasingBST(TreeNode* root) {
    vector<int>* sequence = new vector<int>;
    preOrderTraversal(root, sequence);

    TreeNode* r = new TreeNode(sequence->at(0));
    toTree(sequence, r);

    return r;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        printBinaryTree(increasingBST(root));
    }
    return 0;
}