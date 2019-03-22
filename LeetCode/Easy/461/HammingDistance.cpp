/**
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "../headers/leetcode.h"

using namespace std;

int hammingDistance(int x, int y) {
    int distance = 0;
    while(x != 0 || y != 0) {
        if(x % 2 != y % 2) {
            distance++;
        }
        x /= 2;
        y /= 2;
    }
    return distance;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int x = readNumber();
        int y = readNumber();
        cout << hammingDistance(x, y) << endl;
    }
    return 0;
}
