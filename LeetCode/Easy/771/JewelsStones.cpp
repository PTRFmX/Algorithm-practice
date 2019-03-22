/**
 * You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.
 * You want to know how many of the stones you have are also jewels.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters. 
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

class Solution {
    public: 
        int numJewelsInStones(string J, string S) {
            int count = 0;
            for(int i = 0; i < J.length(); i++) {
                for(int j = 0; j < S.length(); j++) {
                    if(((S[j] >= 'a' && S[j] <= 'z') && (J[i] >= 'a' && J[i] <= 'z') && (S.substr(j, 1) == J.substr(i, 1))) || ((S[j] >= 'A' && S[j] <= 'Z') && (J[i] >= 'A' && J[i] <= 'Z') && (S.substr(j, 1) == J.substr(i, 1)))) {
                        count ++;
                    }
                    else {
                        continue;
                    }
                }
            }
            return count;
        }
};

int main(int argc, char const *argv[])
{
    string J, S;
    cin >> J >> S;
    Solution solution;
    cout << solution.numJewelsInStones(J, S) << endl;
    system("pause");
    return 0;
}
