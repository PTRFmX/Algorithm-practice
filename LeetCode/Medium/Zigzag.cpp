/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Special Case
        if(s.length() <= numRows) {
            return s;
        }

        if(numRows == 1) {
            return s;
        }

        // Initialize
        int num_of_zip = (s.length()) / (2 * (numRows - 1));

        // IMPORTANT! Here vector<vector<string>> will cause memory limit exceed
        // vector<vector<char>> requires less memory thus got accepted
        vector<vector<char>> total(numRows, vector<char>((num_of_zip + 1) * (numRows - 1)));
        int rows = numRows;
        int cols = (num_of_zip + 1) * (numRows - 1);

        // Put every character of the string in the zipzag order into the vector
        int index_row = 0, index_col = 0;
        for(int i = 0; i < s.length(); i++) {
            total[index_row][index_col] = s[i];
            if(i % (2 * (numRows - 1)) < numRows - 1) {
                index_row ++;
            }
            else {
                index_col ++;
                index_row --;
            }
        }
        
        // Get result
        string result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(total[i][j] != (char) 0) {
                    result += total[i][j];
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    Solution solution;
    cout << solution.convert(str, n) << endl;
    system("pause");
    return 0;
}
