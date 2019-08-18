/**
 * You have a set of tiles, where each tile has one letter tiles[i] printed on it. 
 * Return the number of possible non-empty sequences of letters you can make.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int factorial(int n) {
    int m = 1;
    for (int i = 1; i <= n; i++) {
        m *= i;
    }
    return m;
}

bool equivalent(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                s2.erase(j, 1);
            }
        }
    }

    return s2 == "";
}

int numTilePossibilities(string tiles, vector<string>* all_pos = new vector<string>) {
    if (tiles.length() == 1) {
        return 1;
    }
    vector<char> all_char, all_char_num;
    int count = 0, duplicate = 0;
    for (int i = 0; i < tiles.length(); i++) {
        if (find(all_char.begin(), all_char.end(), tiles[i]) == all_char.end()) {    
            all_char.push_back(tiles[i]);  
            all_char_num.push_back(0);
        }
    }

    for (int i = 0; i < tiles.length(); i++) {
        for (int j = 0; j < all_char.size(); j++) {
            if (all_char[j] == tiles[i]) {
                all_char_num[j] += 1;
            }
        }
    }

    int divisor = 1;
    for (int i = 0; i < all_char_num.size(); i++) {
        divisor *= factorial(all_char_num[i]);
    }

    int current_all_pos = factorial(tiles.length()) / divisor;

    for (int i = 1; i < (1 << tiles.length()); i++) {
        string substr = "";
        bool skip;
        for (int j = 0; j < tiles.length(); j++) {
            int temp = i;
            if (temp & (1 << j)) {
                substr += tiles[j];
            }
        }
        if (find(all_pos->begin(), all_pos->end(), substr) == all_pos->end() && substr != tiles) {
            for (int k = 0; k < all_pos->size(); k++) {
                if (equivalent(all_pos->at(k), substr)) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                all_pos->push_back(substr);
                current_all_pos += numTilePossibilities(substr, all_pos);
            }
        }
    }

    return current_all_pos;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string s = readString();
        cout << numTilePossibilities(s) << endl;
    }
    return 0;
}