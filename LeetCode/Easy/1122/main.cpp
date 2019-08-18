/**
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
 * Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int index = 0;
    for (int i = 0; i < arr2.size(); i++) {
        for (int j = index; j < arr1.size() - 1; j++) {
            if (arr2[i] != arr1[j]) {
                bool exist;
                for (int k = j + 1; k < arr1.size(); k++) {
                    if (arr1[k] == arr2[i]) {
                        exist = true;
                        int temp = arr1[j];
                        arr1[j] = arr1[k];
                        arr1[k] = temp;
                        index = j + 1;
                        break;
                    }
                }
                if (!exist) {
                    break;
                }
            }
            else {
                index++;
            }
        }
    }
    for (int i = index; i < arr1.size() - 1; i++) {
        for (int j = i + 1; j < arr1.size(); j++) {
            if (arr1[i] > arr1[j]) {
                int temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;
            }
        }
    }
    return arr1;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int s1 = readNumber();
        vector<int> arr1 = readVector(s1);
        int s2 = readNumber();
        vector<int> arr2 = readVector(s2);
        printVector(relativeSortArray(arr1, arr2));
    }
    return 0;
}