/**
 * Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B 
 * where V = |A.val - B.val| and A is an ancestor of B.
 * (A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

int getMax(TreeNode* root, int maximum, int minimum) {
    if (root == nullptr) {
        return maximum - minimum;
    }
    maximum = max(maximum, root->val);
    minimum = min(minimum, root->val);
    return max(getMax(root->left, maximum, minimum), getMax(root->right, maximum, minimum));
}
    
int maxAncestorDiff(TreeNode* root) {
    return getMax(root, root->val, root->val);
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        cout << maxAncestorDiff(root) << endl;
    }
    return 0;
}
