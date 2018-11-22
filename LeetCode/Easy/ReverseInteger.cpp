/**
 * Given a 32-bit signed integer, reverse digits of an integer.
*/

// Though in the Easy Division, this question is quite tricky when addressing int overflows. Personally I dislike this problem very much.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        vector<int> rem;
        while(x != 0) {
            rem.push_back(x % 10);
            x /= 10;
        }       

        /** Note that when processing overflow, you can not judge a already-overflowed int overflows or not.
         * For example you can't do if(x > INT_MAX) {return 0;}
         * One way to detect overflow is to judge between the current var and after-operation var
         * Ex: If you want to judge whether a*b overflows, do if(a > INT_MAX / b) {return 0;}
        */ 

        for(int i = 0; i < rem.size(); i++) {
            int temp = rem[rem.size() - 1 - i] * pow(10, i);
            if(rem[0] > 2 && rem.size() == 10) {
                return 0;
            }
            if(temp > 0) {
                if(sum > INT_MAX - temp) {
                    return 0;
                }
            }
            else if(temp < 0) {
                if(sum < INT_MIN - temp) {
                    return 0;
                }
            }
            sum += temp;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.reverse(n) << endl;
    system("pause");
    return 0;
}
