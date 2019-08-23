/**
 * Write a function that reverses a string. The input string is given as an array of characters char[].
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * You may assume all the characters consist of printable ascii characters.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
        char temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<char> s = readCharVector(size);
        reverseString(s);
        printVector(s);
    }
    return 0;
}