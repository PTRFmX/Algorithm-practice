/**
 * In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.
 * Initially, all the cards start face down (unrevealed) in one deck.
 * Now, you do the following steps repeatedly, until all cards are revealed:
 * Take the top card of the deck, reveal it, and take it out of the deck.
 * If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
 * If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
 * Return an ordering of the deck that would reveal the cards in increasing order.
 * The first entry in the answer is considered to be the top of the deck.
*/

#include "../headers/leetcode.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    vector<int> result;
    sort(deck.begin(), deck.end());
    for(int i = deck.size() - 1; i >= 0; i--) {
        if(result.size() >= 2) {
            result.push_back(result[0]);
            for(int j = 0; j < result.size() - 1; j++) {
                result[j] = result[j + 1];
            }
            result.pop_back();
        }
        result.push_back(deck[i]);
    }
    reverse(result.begin(), result.end());
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
        vector<int> deck = readVector(size);
        deckRevealedIncreasing(deck);
    }
    return 0;
}
