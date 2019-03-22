/**
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
 * To flip an image horizontally means that each row of the image is reversed.  
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "../headers/leetcode.h"

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    vector<vector<int>> result;
    for(vector<int> element : A) {
        for(int i = 0; i < element.size() / 2; i++) {
            swap(element[i], element[element.size() - 1 - i]);
        }
        for(int i = 0; i < element.size(); i++) {
            switch(element[i]) {
                case 0:
                    element[i] = 1;
                    break;
                case 1 : 
                    element[i] = 0;
                    break;
            }
        }
        result.push_back(element);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int p = readNumber();
        int n = readNumber();
        vector<vector<int>> A = readGrid(p, n);
        flipAndInvertImage(A);
    }
    return 0;
}