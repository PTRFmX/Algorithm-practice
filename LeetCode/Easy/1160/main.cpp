/**
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * Return the sum of lengths of all good strings in words.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int canBeFormed(string word, string chars) {
    int length = word.length();
    for (int i = 0; i < word.length(); i++) {
        if (chars.find(word[i]) == string::npos) {
            return 0;
        }
        chars.erase(chars.find(word[i]), 1);
    }
    return length;
}

int countCharacters(vector<string>& words, string chars) {
    int sum = 0, length = 0;
    for (int i = 0; i < words.size(); i++) {
        length = canBeFormed(words[i], chars);
        sum += length;
    }
    return sum;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<string> words = readStringVector(size);
        string chars = readString();
        cout << countCharacters(words, chars) << endl;    
    }
    return 0;
}