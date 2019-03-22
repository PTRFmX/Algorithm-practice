/**
Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        
    }
    
    vector<int> pingVec(vector<string> counter) {
        vector<int> result;
        for(int count : counter) {
            result.push_back(ping(count));
        }
        return result;
    }
};

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        vector<string> calls = readVector();
        RecentCounter counter;
        
    }
    return 0;
}