/**
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 
 * Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());
    int minDif = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++) {
        int absDif = abs(arr[i] - arr[i + 1]);
        if (absDif <= minDif) {
            if (absDif < minDif) {
                minDif = absDif;
                result = {};
            }
            result.push_back({min(arr[i], arr[i + 1]), max(arr[i], arr[i + 1])});
        }
    }
    return result;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> v = readVector(size);
        printGrid(minimumAbsDifference(v));
    }
    return 0;
}