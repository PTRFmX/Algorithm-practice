/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
*/

// 1 minute trash question

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            bool result = true;
            string str = to_string(x);
            for(int i = 0; i < str.length() / 2; i++) {
                if(str.substr(i, 1) != str.substr(str.length() - 1 - i, 1)) {
                    result = false;
                }
            }
            return result;
        }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.isPalindrome(n) << endl;
    system("pause");
    return 0;
}
