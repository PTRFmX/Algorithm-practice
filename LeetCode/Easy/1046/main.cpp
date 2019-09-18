/**
 * We have a collection of rocks, each rock has a positive integer weight.
 * Each turn, we choose the two heaviest rocks and smash them together.
 * Suppose the stones have weights x and y with x <= y. The result of this smash is:
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 */

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;
    
int lastStoneWeight(vector<int>& stones) {
    while (stones.size() > 1) {
        int largest = 1, snd_largest = 0;
        if (stones[snd_largest] > stones[largest]) {
            largest = 0, snd_largest = 1;
        }
        int arr[2] = {largest, snd_largest};
        for (int i = 2; i < stones.size(); i++) {
            if (stones[i] > stones[arr[0]]) {
                arr[1] = arr[0];
                arr[0] = i;
            }
            else if (stones[i] <= stones[arr[0]] && stones[i] > stones[arr[1]]) {
                arr[1] = i;
            }
        }

        stones[arr[0]] -= stones[arr[1]];
        if (stones[arr[0]] == 0) {
            stones.erase(stones.begin() + arr[0]);
            if (arr[0] < arr[1]) {
                arr[1]--;
            }
        }
        stones.erase(stones.begin() + arr[1]);
    }
    if (stones.size() == 0) {
        return 0;
    }
    return stones[0];
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> stones = readVector(size);
        cout << lastStoneWeight(stones) << endl;
    }
    return 0;
}
