/**
 * P1031 Moving cards
 * 思路类似快排
 * 第一次处理后左边的sum恒小于右侧
 * 第二次从右侧开始排回n
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialization
    int m, moveCount = 0, avg, sum = 0;
    cin >> m;
    int arr[m];
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    avg = sum / m;

    // First time movement
    int subsum = 0;
    for(int i = 0; i < m - 1; i++) {
        subsum += arr[i] - avg;
        if(subsum > 0) {
            arr[i] -= subsum;
            arr[i + 1] += subsum;
            moveCount++;
            subsum = 0;
        }
        else if(subsum == 0) {
            continue;
        }
    }

    // Second time movement
    for(int i = m - 1; i > 0; i--) {
        if(arr[i] > avg) {
            arr[i - 1] += arr[i] - avg;
            arr[i] -= arr[i] - avg;      
            moveCount++;
        }
        else {
            continue;
        }
    }

    //Print result
    cout << moveCount << endl;
    cin >> m;
    return 0;
}
