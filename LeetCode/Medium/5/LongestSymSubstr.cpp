/**
 * Given a string, find the length of the longest substring without repeating characters.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {

            vector<string> list;

            for(int k = 0; k < s.length(); k++) {
                bool next = false, isSymmetric = true;
                for(int i = k; i < s.length(); i++) {
                    for(int p = s.length() - i; p >= 0 ; p--) {
                        string str = s.substr(i, p);
                        isSymmetric = true;}
                        for(int j = 0; j < str.length() / 2; j++) {
                            if(str.substr(j, 1) != str.substr(str.length() - 1 - j, 1)) {
                                isSymmetric = false;
                                break;
                            }
                        }
                        if(isSymmetric) {
                            list.push_back(str);
                            next = true;
                            break;
                        }
                    }
                    
                    if(next) {
                        break;
                    }
                }
            }

            string longest = "";
            for(int i = 0; i < list.size(); i++) {
                if(list[i].length() > longest.length()) {
                    longest = list[i];
                }
            }

            return longest;
        }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.longestPalindrome(str) << endl;
    system("pause");
    return 0;
}