/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) {
        return l2;
    }
    if(l2 == nullptr) {
        return l1;
    }
    vector<int> result; 
    while(l1->next != nullptr) {
        result.push_back(l1->val);
        l1 = l1->next;
    }
    result.push_back(l1->val);
    while(l2->next != nullptr) {
        result.push_back(l2->val);
        l2 = l2->next;
    }
    result.push_back(l2->val);
    sort(result.begin(), result.end());
    ListNode* head = new ListNode(result[0]);
    ListNode* temp = head;
    for(int i = 1; i < result.size(); i++) {
        temp->next = new ListNode(result[i]);
        temp = temp->next;
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
        ListNode* l1 = readLinkedList(size);
        ListNode* l2 = readLinkedList(size);
        printLinkedList(mergeTwoLists(l1, l2));
    }
    return 0;
}