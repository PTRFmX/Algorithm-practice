#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

bool hasEnd(string s, int sum_length);
void eleven(string s, int sum_length);
void twentyOne(string s, int sum_length);

int main(int argc, char const *argv[])
{
    string sum, s;
    int sum_length;
    while(cin >> s) {
        sum.append(s);
        sum_length = sum.length();
        if(hasEnd(s, sum_length)) {
            eleven(sum, sum_length);
            cout << endl;
            twentyOne(sum, sum_length);
            break;
        }
    }
    cin >> s;
    return 0;
}

bool hasEnd(string s, int sum_length) {
    for(int i = 0; i < sum_length; i++) {
        if(s[i] == 'E') {
            return true;
        }
    }
    return false;
}

void eleven(string s, int sum_length) {
    int w_count = 0, l_count = 0;
    for(int i = 0; i < sum_length; i++){
        if(s[i] == 'W') {
            w_count++;
            if(w_count >= 11 && abs(w_count - l_count) >= 2) {
                cout << w_count << ':' << l_count << endl;
                w_count = 0;
                l_count = 0;
            }
            else {
                continue;
            }    
        }
        else if(s[i] == 'L') {
            l_count++;
            if(l_count >= 11 && abs(w_count - l_count) >= 2) {
                cout << w_count << ':' << l_count << endl;
                w_count = 0;
                l_count = 0;
            }
            else {
                continue;
            } 
        }
        else {
            cout << w_count << ':' << l_count << endl;
        }
    }
}

void twentyOne(string s, int sum_length) {
    int w_count = 0, l_count = 0;
    for(int i = 0; i < sum_length; i++){
        if(s[i] == 'W') {
            w_count++;
            if(w_count >= 21 && abs(w_count - l_count) >= 2) {
                cout << w_count << ':' << l_count << endl;
                w_count = 0;
                l_count = 0;
            }
            else {
                continue;
            }    
        }
        else if(s[i] == 'L') {
            l_count++;
            if(l_count >= 21 && abs(w_count - l_count) >= 2) {
                cout << w_count << ':' << l_count << endl;
                w_count = 0;
                l_count = 0;
            }
            else {
                continue;
            } 
        }
        else {
            cout << w_count << ':' << l_count << endl;
        }
    }
}