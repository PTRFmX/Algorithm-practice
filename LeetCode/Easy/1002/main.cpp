/**
 * Given an array A of strings made only from lowercase letters, 
 * return a list of all characters that show up in all strings within the list (including duplicates).  
 * For example, if a character occurs 3 times in all strings but not 4 times, 
 * you need to include that character three times in the final answer.
 * You may return the answer in any order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<string> commonChars(vector<string>& A) {
    vector<string> result;
    for (int i = 0; i < A[0].length(); i++) {
        string c = A[0].substr(i, 1);
        bool addNew = true;
        for (int j = 1; j < A.size(); j++) {
            if (A[j].find(c) == string::npos) {
                addNew = false;
                break;
            }
            else {
                int pos = A[j].find(c);
                A[j].erase(pos, 1);
            }
        }
        if (addNew) {
            result.push_back(c);
        }
    }
    return result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<string> s = readStringVector(size);
        printVector(commonChars(s));
    }
    return 0;
}