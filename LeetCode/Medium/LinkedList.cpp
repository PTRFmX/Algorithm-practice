/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// void createNode(int value);
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head = new ListNode(0);
            ListNode* p = l1;
            ListNode* q = l2;
            ListNode* cur = head;
            int moreThanTen = 0, sum = 0;
            while(p != nullptr || q != nullptr) {
                int p_value = (p == nullptr) ? 0 : p->val;
                int q_value = (q == nullptr) ? 0 : q->val;
                sum = moreThanTen + p_value + q_value;
                moreThanTen = sum / 10;
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                if(p != nullptr) {
                    p = p->next;
                }
                if(q != nullptr) {
                    q = q->next;
                }
            }
            if(moreThanTen > 0) {
                cur->next = new ListNode(moreThanTen);
            }
            return head->next;
        }
};

int main(int argc, char const *argv[])
{
    int n;
    vector<int> v1, v2;
    ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
    ListNode *l1 = head1, *l2 = head2;
    while(cin >> n) {
        v1.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }
    for(int i = v1.size() - 1; i >= 0; i--) {
        l1->next = new ListNode(v1[i]);
        l1 = l1->next;
    }

    while(cin >> n) {
        v2.push_back(n);
        if(getchar() == '\n') {
            break;
        }
    }
    for(int i = v2.size() - 1; i >= 0; i--) {
        l2->next = new ListNode(v2[i]);
        l2 = l2->next;
    }

    Solution solution;
    ListNode *result = solution.addTwoNumbers(head1->next , head2->next);
    while(result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    system("pause");
    return 0;
}
