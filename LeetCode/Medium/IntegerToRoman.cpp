/**
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            vector<int> index;
            string str;
            while(num != 0) {
                index.push_back(num % 10);
                num /= 10;
            }
            vector<string> roman_1 = {"I", "X", "C", "M"};
            vector<string> roman_2 = {"V", "L", "D"};
            for(int i = index.size() - 1; i >= 0; i--) {
                if(index[i] == 0) {
                    str += "";
                }
                else if(index[i] >= 1 && index[i] <= 3) {
                    for(int k = 1; k <= index[i]; k++) {
                        str += roman_1[i];
                    }
                }
                else if(index[i] >= 4 && index[i] <= 8) {
                    if(index[i] == 4) {
                        str += roman_1[i] + roman_2[i];
                    }
                    else {
                        str += roman_2[i];
                        for(int p = 0; p < index[i] - 5; p++) {
                            str += roman_1[i];
                        }
                    }
                }
                else {
                    if(index[i] == 9) {
                        str += roman_1[i] + roman_1[i + 1];
                    }
                }
            }
            return str;
        }
        
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.intToRoman(n) << endl;
    system("pause");
    return 0;
}