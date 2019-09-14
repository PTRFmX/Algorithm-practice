/**
 * Alex and Lee play a game with piles of stones.
 * There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
 * The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
 * Alex and Lee take turns, with Alex starting first.
 * Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.
 * This continues until there are no more piles left, at which point the person with the most stones wins.
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 
#include <bitset>

using namespace std;

/**
 * --------------------------- LEETCODE SOLUTION -----------------------------
 * 
 * Intuition
 * Let's change the game so that whenever Lee scores points, it deducts from Alex's score instead.
 * Let dp(i, j) be the largest score Alex can achieve where the piles remaining are piles[i], piles[i+1], ..., piles[j]. This is natural in games with scoring: we want to know what the value of each position of the game is.
 * We can formulate a recursion for dp(i, j) in terms of dp(i+1, j) and dp(i, j-1), and we can use dynamic programming to not repeat work in this recursion. (This approach can output the correct answer, because the states form a DAG (directed acyclic graph).)
 * 
 * Algorithm
 * When the piles remaining are piles[i], piles[i+1], ..., piles[j], the player who's turn it is has at most 2 moves.
 * The person who's turn it is can be found by comparing j-i to N modulo 2.
 * If the player is Alex, then she either takes piles[i] or piles[j], increasing her score by that amount. Afterwards, the total score is either piles[i] + dp(i+1, j), or piles[j] + dp(i, j-1); and we want the maximum possible score.
 * If the player is Lee, then he either takes piles[i] or piles[j], decreasing Alex's score by that amount. Afterwards, the total score is either -piles[i] + dp(i+1, j), or -piles[j] + dp(i, j-1); and we want the minimum possible score.
*/
bool stoneGame(vector<int>& piles) {
    int N = piles.size();
    // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
    int dp[N+2][N+2];
    memset(dp, 0, sizeof(dp));
    for (int size = 1; size <= N; ++size)
        for (int i = 0, j = size - 1; j < N; ++i, ++j) {
            int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
            else
                dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
        }
    return dp[1][N] > 0;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> piles = readVector(size);
        cout << stoneGame(piles) << endl;
    }
    return 0;
}