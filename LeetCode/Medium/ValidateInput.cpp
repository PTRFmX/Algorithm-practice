/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) {
            return true;
        }
        if(s.length() % 2 != 0) {
            return false;
        }
        stack<string> stk;   
        for(int i = 0; i < s.length(); i++) {
            if(s.substr(i, 1) == "(") {
                stk.push(s.substr(i, 1));
            }
            else if(s.substr(i, 1) == ")") {

                // It is very important here to put !stk.empty() in front of stk.top() since stk.top() will return the top element
                // If stk is empty, top() will cause runtime error. But if you put it in the front, stk.top() will not execute since the first statement is false
                if(!stk.empty() && stk.top() == "(") {
                    stk.pop();
                }
                else {
                    stk.push(s.substr(i, 1));
                }
            }

            // Ctrl + C/V

            if(s.substr(i, 1) == "[") {
                stk.push(s.substr(i, 1));
            }
            else if(s.substr(i, 1) == "]") {
                if(!stk.empty() && stk.top() == "[") {
                    stk.pop();
                }
                else {
                    stk.push(s.substr(i, 1));
                }
            }

            if(s.substr(i, 1) == "{") {
                stk.push(s.substr(i, 1));
            }
            else if(s.substr(i, 1) == "}") {
                if(!stk.empty() && stk.top() == "{") {
                    stk.pop();
                }
                else {
                    stk.push(s.substr(i, 1));
                }
            }
        }

        return stk.empty();
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    Solution solution;
    cout << solution.isValid(str) << endl;
    system("pause");
    return 0;
}
