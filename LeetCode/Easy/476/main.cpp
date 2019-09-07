/**
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

int findComplement(int num) {
    int result = num, count = 0;
    while(num) {
        result ^= (1 << count);
        num /= 2;
        count++;
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
        int n = readNumber();
        cout << findComplement(n) << endl;
    }
    return 0;
}