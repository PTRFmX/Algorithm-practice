/**
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void postorderUtil(Node* root, vector<int>* result) {
    if (root == nullptr) {
        return;
    }
    for(int i = 0; i < root->children.size(); i++) {
        postorderUtil(root->children.at(i), result);
    }
    result->push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int>* result = new vector<int>;
    postorderUtil(root, result);
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
        printVector(postorder(root));
    }
    return 0;
}