/**
 * Given a string, find the length of the longest substring without repeating characters.
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            // Initialize
            vector<string> result;
            bool hasNoCommonCharac = true;

            // Find all substrs who have no same characters
            for(int i = 0; i < s.length(); i++) {
                for(int j = 1; j < s.length() - i + 1; j++) {

                    // Find all the substr possible
                    string substr = s.substr(i, j);
                    
                    // Handle with those who have multiple same characters. Mark those as false.
                    vector<string> characSet;
                    if(substr.length() == 1) {
                        result.push_back(substr);
                    }
                    else {
                        for(int k = 0; k < substr.length(); k++) {
                            characSet.push_back(substr.substr(k, 1));
                        }
                        for(int m = 0; m < characSet.size(); m++) {
                            for(int n = m; n < characSet.size(); n++) {
                                if(characSet[m] == characSet[n] && m != n) {
                                    hasNoCommonCharac = false;
                                }
                            }
                        }
                        
                        // Add purified substrs to result
                        if(hasNoCommonCharac) {
                            result.push_back(substr);
                        }
                    }
                    // Reset hasNoCommonCharac
                    hasNoCommonCharac = true;
                }
            }

            int length = 0;
            for(int i = 0; i < result.size(); i++) {
                if(result[i].length() > length) {
                    length = result[i].length();
                }
            }

            return length;
        }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(str) << endl;
    system("pause");
    return 0;
}