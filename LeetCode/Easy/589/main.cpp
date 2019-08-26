/**
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void preorderUtil(Node* root, vector<int>* result) {
    if (root == nullptr) {
        return;
    }
    result->push_back(root->val);
    for(int i = 0; i < root->children.size(); i++) {
        preorderUtil(root->children.at(i), result);
    }
}

vector<int> preorder(Node* root) {
    vector<int>* result = new vector<int>;
    preorderUtil(root, result);
    return *result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n_arr = readNumber();
        Node* root = readAryTree(n_arr);
        printVector(preorder(root));
    }
    return 0;
}