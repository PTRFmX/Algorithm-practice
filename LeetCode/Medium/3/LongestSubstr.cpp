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
            vector<int> length;

            // Idea: Start from k, select temp str that is as long as possible (does not have 2 same character in the string)
            for(int k = 0; k < s.length(); k++) {
                vector<string> temp;

                // Next symbolizes whether to jump out of i loop and start over at k + 1
                bool next = false;

                for(int i = k; i < s.length(); i++) {
                    temp.push_back(s.substr(i, 1));
                    for(int j = 0; j < temp.size() - 1; j++) {
                        if(temp[j] == s.substr(i, 1)) {
                            // Delete if the newly added element is redundant and start over
                            temp.pop_back();
                            next = true;
                            break;
                        }
                    }
                    if(next) {
                        break;
                    }
                }

                // Add the length of substr to length (vector<int>)
                length.push_back(temp.size());
            }

            // Find the biggest length
            int biggest = 0;
            for(int i = 0; i < length.size(); i++) {
                if(length[i] > biggest) {
                    biggest = length[i];
                }
            }

            return biggest;
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