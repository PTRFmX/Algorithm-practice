/**
 * Given an array of integers nums, sort the array in ascending order.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

// O(n^2) will cause TLE, use MergeSort instead
void Merge(vector<int>* v, int begin, int end, int mid) {
    int i = begin, j = mid + 1, k = 0, size = end - begin + 1;
    int arr[size];
    while (i <= mid && j <= end) {
        if (v->at(i) <= v->at(j)) {
            arr[k++] = v->at(i++);
        }
        else {
            arr[k++] = v->at(j++);
        }
    }
    while (i <= mid){
        arr[k++] = v->at(i++);
    }
    while (j <= end) {
        arr[k++] = v->at(j++);
    }
    for (i = begin; i <= end; i++) {
		v->at(i) = arr[i - begin];
	}
}

void MergeSort(vector<int>* v, int begin, int end) {
    int mid;
    if (begin < end) {
        mid = (begin + end) / 2;
        MergeSort(v, begin, mid);
        MergeSort(v, mid + 1, end);
        Merge(v, begin, end, mid);
    }
}

vector<int> sortArray(vector<int>& nums) {
    vector<int>* v = &nums;
    MergeSort(v, 0, v->size() - 1);
    return nums;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<int> nums = readVector(size);
        printVector(sortArray(nums));
    }
    return 0;
}