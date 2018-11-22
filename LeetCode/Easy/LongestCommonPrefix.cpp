/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 0) {
                return "";
            }
            int shortestLength = strs[0].length();
            for(int i = 1; i < strs.size(); i++) {
                if(shortestLength > strs[i].length()) {
                    shortestLength = strs[i].length();
                }
            }
            string result = "";
            for(int i = 0; i <= shortestLength; i++) {
                bool consistent = true;
                for(int j = 1; j < strs.size(); j++) {
                    if(strs[j - 1].substr(0, i) != strs[j].substr(0, i)) {
                        consistent = false;
                    }
                }
                if(consistent) {
                    result = strs[0].substr(0, i);
                }
            }
            return result;
        }
};

int main(int argc, char const *argv[])
{
    string str;
    vector<string> strs;
    while(cin >> str) {
        strs.push_back(str);
        if(getchar() == '\n') {
            break;
        }
    }
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;
    system("pause");
    return 0;
}
