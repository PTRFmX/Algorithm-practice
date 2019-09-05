/**
 * Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void findInRow(vector<string>* v, vector<char> row, string w) {
    bool inWords = true;
    for (int i = 1; i < w.length(); i++) {
        if (find(row.begin(), row.end(), (w[i] <= 90 ? w[i] + 32 : w[i])) == row.end()) {
            inWords = false;
            break;
        }
    }
    if (inWords) {
        v->push_back(w);
    }
}

vector<string> findWords(vector<string>& words) {
    vector<string>* result = new vector<string>;
    vector<char> row_q = {'q', 'w', 'e' , 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    vector<char> row_a = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    vector<char> row_z = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    for (string w : words) {
        char c = w[0];
        if (c <= 90) c += 32;
        if (find(row_q.begin(), row_q.end(), c) != row_q.end()) {
            findInRow(result, row_q, w);
        }
        else if (find(row_a.begin(), row_a.end(), c) != row_a.end()) {
            findInRow(result, row_a, w);
        }
        else if (find(row_z.begin(), row_z.end(), c) != row_z.end()) {
            findInRow(result, row_z, w);
        }
    }
    return *result;
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
        printVector(findWords(s));
    }
    return 0;
}