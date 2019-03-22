/**
 * A self-dividing number is a number that is divisible by every digit it contains.
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    bool isSelfDividing;
    for(int i = left; i <= right; i++) {
        isSelfDividing = true;
        int temp = i;
        while(temp != 0) {
            if(temp % 10 == 0) {
                isSelfDividing = false;
                break;
            }
            else if(i % (temp % 10) != 0) {
                isSelfDividing = false;
            }
            temp /= 10;
        }
        if(isSelfDividing) {
            result.push_back(i);
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
        int left = readNumber();
        int right = readNumber();
        selfDividingNumbers(left, right);
    }
    return 0;
}