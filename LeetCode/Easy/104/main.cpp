/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        cout << maxDepth(root) << endl;
    }
    return 0;
}
