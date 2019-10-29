/**
 * Given a function  f(x, y) and a value z, return all positive integer pairs x and y where f(x,y) == z.
 * The function is constantly increasing, i.e.:
 * f(x, y) < f(x + 1, y)
 * f(x, y) < f(x, y + 1)
 * The function interface is defined like this: 
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> result;
    for (int i = 1; i <= z; i++) {
        for (int j = 1; j <= z; j++) {
            if (customfunction.f(i, j) == z) {
                result.push_back({i, j});
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
        // Passed directly through leetcode. No need to test on local IDE
    }
    return 0;
}