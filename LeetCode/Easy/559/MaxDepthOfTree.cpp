/**
 * Given a n-ary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * For example, given a 3-ary tree:
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int maxDepth(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    if(root->children.size() == 0) {
        return 1;
    }

    vector<int> childrenDepth;
    for (int i = 0; i < root->children.size(); i++) {
        childrenDepth.push_back(1 + maxDepth(root->children[i]));
    }

    int max = 1;
    for(int i = 0; i < childrenDepth.size(); i++) {
        if(childrenDepth[i] > max) {
            max = childrenDepth[i];
        }
    }
    return max;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int k_ary = readNumber();
        Node* root = readAryTree(k_ary);
        cout << maxDepth(root) << endl;
    }
    return 0;
}