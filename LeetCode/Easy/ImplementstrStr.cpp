/**
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() - needle.length() < 0) {
            return -1;
        }
        if(haystack == needle) {
            return 0;
        }
        int index = -1;
        for(int i = haystack.length() - 1; i >= 0; i--) {
            if(haystack.length() >= i + needle.length() && haystack.substr(i, needle.length()) == needle) {
                index = i;
            }
        }
        return index;
    }
};

int main(int argc, char const *argv[])
{
    string haystack, needle;
    cin >> haystack >> needle;
    Solution solution;
    cout << solution.strStr(haystack, needle) << endl;
    system("pause");
    return 0;
}
