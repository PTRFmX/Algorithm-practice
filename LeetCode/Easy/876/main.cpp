/**
 * Given a non-empty, singly linked list with head node head, return a middle node of linked list.
 * If there are two middle nodes, return the second middle node.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int getSize(ListNode* head) {
    int count = 0;
    while(head != nullptr){
        head = head->next;
        count++;
    }
    return count;
}

ListNode* middleNode(ListNode* head) {
    int mid = getSize(head) / 2;
    for (int i = 0; i < mid; i++) {
        head = head->next;
    }
    return head;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        ListNode* node = readLinkedList(size);
        printLinkedList(middleNode(node));    
    }
    return 0;
}