/**
 * 
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<string> split(char needle, string text) {
    vector<string> result;
    while(text.find(needle) != string::npos){
        int pos = text.find(needle);
        result.push_back(text.substr(0, pos));
        text = text.substr(pos + 1, text.length() - pos - 1);
    }
    result.push_back(text);
    return result;
}

vector<string> findOcurrences(string text, string first, string second) {
    vector<string> all_words = split(' ', text), result = {};
    for (int i = 0; i < all_words.size() - 2; i++) {
        if (all_words[i] == first && all_words[i + 1] == second) {
            result.push_back(all_words[i + 2]);
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
        cin.ignore();
        string text = readStringLine();
        string first = readString();
        string second = readString();
        printVector(findOcurrences(text, first, second));
    }
    return 0;
}