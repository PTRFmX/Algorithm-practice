/**
 * You have a list of words and a pattern, and you want to know which words in words matches the pattern.
 * A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
 * (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
 * Return a list of the words in words that match the given pattern. 
 * You may return the answer in any order.
*/

#include "../headers/leetcode.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> result;
    map<char, char> pat, pat_corres;
    bool consistent = true;
    for(string word : words) {
        pat.clear();
        pat_corres.clear();
        consistent = true;
        if(word.length() != pattern.length()) {
            continue;
        }
        for(int i = 0; i < word.length(); i++) {
            if(pat.find(word[i]) == pat.end() && pat_corres.find(pattern[i]) == pat_corres.end()) {
                // cout << word[i] << " " << pattern[i] << endl;
                pat.insert(make_pair(word[i], pattern[i]));
                pat_corres.insert(make_pair(pattern[i], word[i]));
            }
            else if(pat[word[i]] != pattern[i] || pat_corres[pattern[i]] != word[i]) {
                consistent = false;
            }
        }
        if(consistent) {
            result.push_back(word);
        }
    }

    // Test
    // for(int i = 0; i < result.size(); i++) {
    //     cout << result[i] << endl;
    // }

    return result;
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<string> words = readStringVector(size);
        string pattern = readString();
        findAndReplacePattern(words, pattern);
    }
    return 0;
}