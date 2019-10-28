/**
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
 *
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

// Passed directly through leetcode. No need to test on local IDE

void getAllLevels(TreeNode* root, vector<int>* v, int depth = 0) {
    if (root == nullptr) {
        return;
    }
    if (v->size() > depth) {
        v->at(depth) += root->val;
    }
    else {
        v->push_back(root->val);
    }
    getAllLevels(root->left, v, ++depth);
    getAllLevels(root->right, v, depth);
    return;
}
    
int maxLevelSum(TreeNode* root) {
    vector<int>* v = new vector<int>;
    getAllLevels(root, v);
    int largest = INT_MIN, largest_level = -1;
    for (int i = 0; i < v->size(); i++) {
        if (v->at(i) > largest) {
            largest = v->at(i);
            largest_level = i + 1;
        }
    }
    return largest_level;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        
    }
    return 0;
}