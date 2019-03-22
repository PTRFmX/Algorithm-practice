/**
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
 * Return the element repeated N times.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int repeatedNTimes(vector<int>& A) {
    int result = -1;
    int temp = -1; 
    for(int e : A) {
        if(e == temp) {
            continue;
        }
        else {
            temp = e;
        }
        if(count(A.begin(), A.end(), e) == A.size() / 2) {
            return e;
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
        vector<int> A = readVector(size);
        cout << repeatedNTimes(A) << endl;
    }
    return 0;
}