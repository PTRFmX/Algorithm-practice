/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1
 * Given N, calculate F(N)
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int fib(int N) {
    vector<int> fibon;
    if(N == 0) {
        return 0;
    }
    if(N == 1) {
        return 1;
    }

    fibon.push_back(0);
    fibon.push_back(1);
    
    for(int i = 0; i < N - 1; i++) {
        fibon.push_back(fibon[i] + fibon[i + 1]);
    }

    return fibon[fibon.size() - 1];
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int N = readNumber();
        cout << fib(N) << endl;
    }
    return 0;
}