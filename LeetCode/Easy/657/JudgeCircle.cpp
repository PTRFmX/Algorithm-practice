/**
 * There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
 * The move sequence is represented by a string, and the character moves[i] represents its ith move. 
 * Valid moves are R (right), L (left), U (up), and D (down). 
 * If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
 * Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. 
 * Also, assume that the magnitude of the robot's movement is the same for each move.
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../headers/leetcode.h"

using namespace std;

bool judgeCircle(string moves) {
    vector<int> coor = {0, 0};
    for(char alphabet : moves) {
        if(alphabet == 'U') {
            coor[0] ++;
        }
        if(alphabet == 'D') {
            coor[0] --;
        }
        if(alphabet == 'L') {
            coor[1] ++;
        }
        if(alphabet == 'R') {
            coor[1] --;
        }
    }
    return (coor[0] == 0 && coor[1] == 0);
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        string moves = readString();
        cout << judgeCircle(moves) << endl;
    }
    return 0;
}