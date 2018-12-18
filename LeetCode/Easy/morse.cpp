/**
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
 * Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. 
 * For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
 * Return the number of different transformations among all words we have.
*/

#include <iostream>
#include <vector>
#include "../headers/leetcode.h"

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    map<char, string> codes;
    set<string> morses;
    codes['A'] = ".-"; codes['a'] = ".-";
    codes['B'] = "-..."; codes['b'] = "-...";
    codes['C'] = "-.-."; codes['c'] = "-.-.";
    codes['D'] = "-.."; codes['d'] = "-..";
    codes['E'] = "."; codes['e'] = ".";
    codes['F'] = "..-."; codes['f'] = "..-.";
    codes['G'] = "--."; codes['g'] = "--.";
    codes['H'] = "...."; codes['h'] = "....";
    codes['I'] = ".."; codes['i'] = "..";
    codes['J'] = ".---"; codes['j'] = ".---";
    codes['K'] = "-.-"; codes['k'] = "-.-";
    codes['L'] = ".-.."; codes['l'] = ".-..";
    codes['M'] = "--"; codes['m'] = "--";
    codes['N'] = "-."; codes['n'] = "-.";
    codes['O'] = "---"; codes['o'] = "---";
    codes['P'] = ".--."; codes['p'] = ".--.";
    codes['Q'] = "--.-"; codes['q'] = "--.-";
    codes['R'] = ".-."; codes['r'] = ".-.";
    codes['S'] = "..."; codes['s'] = "...";
    codes['T'] = "-"; codes['t'] = "-";
    codes['U'] = "..-"; codes['u'] = "..-";
    codes['V'] = "...-"; codes['v'] = "...-";
    codes['W'] = ".--"; codes['w'] = ".--";
    codes['X'] = "-..-"; codes['x'] = "-..-";
    codes['Y'] = "-.--"; codes['y'] = "-.--";
    codes['Z'] = "--.."; codes['z'] = "--..";
    for(int i = 0; i < words.size(); i++) {
        string str = "";
        for(char n : words[i]) {
            str += codes[n];
        }
        morses.insert(str);
    }
    
    return morses.size();
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
        cout << uniqueMorseRepresentations(words) << endl;
    }
    return 0;
}
