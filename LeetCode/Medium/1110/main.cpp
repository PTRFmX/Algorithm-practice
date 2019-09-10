/**
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 * Return the roots of the trees in the remaining forest.  You may return the result in any order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

vector<TreeNode*> getAllTrees(TreeNode** root, vector<int>& to_delete, vector<TreeNode*>* all_trees) {
    if (*root == nullptr) {
        return *all_trees;
    }

    TreeNode* r = *root;

    if (find(to_delete.begin(), to_delete.end(), r->val) != to_delete.end()) {
        if (r->left != nullptr && find(to_delete.begin(), to_delete.end(), r->left->val) == to_delete.end()) {
            all_trees->push_back(r->left);
        }
        if (r->right != nullptr && find(to_delete.begin(), to_delete.end(), r->right->val) == to_delete.end()) {
            all_trees->push_back(r->right);
        }
        *root = nullptr;
    }

    if (r->left != nullptr) {
        TreeNode** lt = &(r->left);
        getAllTrees(lt, to_delete, all_trees);
    }
    if (r->right != nullptr) {
        TreeNode** rt = &(r->right);
        getAllTrees(rt, to_delete, all_trees);
    }

    return *all_trees;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> all_trees;
    vector<TreeNode*>* all_trees_p = &all_trees;
    if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
        all_trees_p->push_back(root);
    }
    TreeNode** r = &root;
    return getAllTrees(r, to_delete, all_trees_p);
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        int size = readNumber();
        vector<int> to_delete = readVector(size);
        vector<TreeNode*> v = delNodes(root, to_delete);
        for (TreeNode* r : v) {
            printBinaryTree(r);
        }
    }
    return 0;
}