/**
 * Given a non negative integer number num. 
 * For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int countBin(unsigned num) {

    if (num == 0) {
        return 0;
    }

    int count = 1;

    while (num > 1) {
        count += num % 2;
        num /= 2;
    }

    return count;
}

vector<int> countBits(int num) {
    vector<int> result;
    for (int i = 0; i <= num; i++) {
        result.push_back(countBin(i));
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
        int num = readNumber();
        printVector(countBits(num));
    }
    return 0;
}