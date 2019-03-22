/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int divide(int dividend, int divisor) {
    // cout << (abs(dividend) - INT_MAX >= 0) << endl;
    if(dividend == 0) {
        return 0;
    }
    if(dividend > 0 && dividend - INT_MAX >= 0) {
        dividend = INT_MAX;
    }
    if(dividend < 0 && - dividend + INT_MIN >= 0) {
        dividend = - INT_MAX;
    }

    cout << dividend << endl;

    int count = 0, sum = 0;

    // if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
    //     while(abs(sum) <= abs(dividend)) {
    //         sum += divisor;
    //         count++;
    //     }
    //     count--;
    // }
    // else if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
    //     while(abs(sum) <= abs(dividend)) {
    //         sum += divisor;
    //         count--;
    //     }
    //     count++;
    // }
    return count;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int dividend = readNumber();
        int divisor = readNumber();
        divide(dividend, divisor);
    }
    return 0;
}