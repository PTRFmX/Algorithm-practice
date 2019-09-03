/**
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
 * Return the intersection of these two interval lists.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> calculateIntersection(vector<int> A, vector<int> B) {
    if (A[1] < B[0] || A[0] > B[1]) {
        return {};
    }

    if (A[0] >= B[0]) {
        if (A[1] <= B[1]) {
            return A;
        }
        return {A[0], B[1]};
    }
    else {
        if (A[1] >= B[1]) {
            return B;
        }
        return {B[0], A[1]};
    }
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {

    if (A.size() == 0 || B.size() == 0) {
        return {};
    }

    int start_index = 0;
    vector<vector<int>> result;
    for (int i = 0; i < B.size(); i++) {
        if (B[i][1] >= A[0][0]) {
            start_index = i;
            break;
        }
    }
    for (int i = 0; i < A.size(); i++) {
        for (int j = start_index; j < B.size(); j++) {
            vector<int> v = calculateIntersection(A[i], B[j]);
            if (v.size() != 0) {
                result.push_back(v);
                start_index = j;
            }
        }
    }
    return result;
}


int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int row_A = readNumber();
        vector<vector<int>> A = readGrid(row_A, 2);
        int row_B = readNumber();
        vector<vector<int>> B = readGrid(row_B, 2);
        printGrid(intervalIntersection(A, B));
    }
    return 0;
}