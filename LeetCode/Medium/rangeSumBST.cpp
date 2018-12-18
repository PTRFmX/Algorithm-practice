/**
 * Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
 * The binary search tree is guaranteed to have unique values.
*/

#include "../headers/leetcode.h"
#include <iostream>

using namespace std;

int rangeSumBST(TreeNode* root, int L, int R) {
    if(root == nullptr) {
        return 0;
    }

    if(root -> val < L) {
        return rangeSumBST(root -> right, L, R);
    }
    if(root -> val > R) {
        return rangeSumBST(root -> left, L, R);
    }
    else {
        return root -> val + rangeSumBST(root -> left, L, R) + rangeSumBST(root -> right, L, R);
    }
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        TreeNode* root = readBinaryTree();
        int l = readNumber(), r = readNumber();
        cout << rangeSumBST(root, l, r) << endl;
    }
    return 0;
}
