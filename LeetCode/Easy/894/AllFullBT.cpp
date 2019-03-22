/**
 * A full binary tree is a binary tree where each node has exactly 0 or 2 children.
 * Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
 * Each node of each tree in the answer must have node.val = 0.
 * You may return the final list of trees in any order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<TreeNode*> allPossibleFBT(int N) {
    
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int N = readNumber();
        allPossibleFBT(N);
    }
    return 0;
}