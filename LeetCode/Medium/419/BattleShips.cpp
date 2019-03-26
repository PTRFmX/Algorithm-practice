/**
 * Share Given an 2D board, count how many battleships are in it. 
 * The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. 
 * In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int countBattleships(vector<vector<char>>& board) {

    if (board.size() == 0) {
        return 0;
    }

    int row = board.size();
    int col = board[0].size();
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'X') {
                count++;
                for (int temp_i = i + 1; temp_i < row; temp_i++) {
                    if (board[temp_i][j] != '.') {
                        board[temp_i][j] = '.';
                    }
                    else {
                        break;
                    }
                }
                
                for (int temp_j = j + 1; temp_j < col; temp_j++) {
                    if (board[i][temp_j] != '.') {
                        board[i][temp_j] = '.';
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    
    return count;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int row = readNumber();
        int col = readNumber();
        vector<vector<char> > board = readCharGrid(row, col);
        cout << countBattleships(board) << endl;
    }
    return 0;
}