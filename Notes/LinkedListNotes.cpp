/**
 * Notes for singly linked list
*/


#include <iostream>
#include <stdio.h>

using namespace std;

// void createNode(int value);
struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
};

class list {
    private:
        ListNode *head, *tail;
    public:
        list() {
            head = NULL;
            tail = NULL;
        }

        // Create a new node at the end
        void createNode(int value) {
            ListNode *temp;
            temp->data = value;
            temp->next = NULL;
            if(head == NULL) {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
        }

        // Display the values of a list
        void display() {
            ListNode *temp;
            temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        // Insert a value at the start
        void insert_start(int value) {
            ListNode *temp;
            temp->data = value;
            temp->next = head; // Place the new node in front of head
            head = temp; // Set current head to the new node
        }

        // Insert at the end is the same as createNode()

        // Insert at a particular position
        void insert_at_pos(int pos, int value) {
            // Note that when you're trying to insert a node in the middle, you have to handle both the previous node and the next(current_pos) node
            ListNode *prev, *cur, *temp;
            // Get the real current node
            cur = head;
            for(int i = 1; i < pos; i++) {
                prev = cur;
                cur = cur->next;
            }
            // Insert
            temp->data = value;
            prev->next = temp;
            temp->next = cur;
        }

        // Delete at the start
        void delete_start() {
            ListNode *temp;
            temp = head;
            head = head->next;
            delete temp;
        }

        // Delete at the last
        void delete_last() {
            ListNode *prev, *cur;
            // Get cur as the last node
            cur = head;
            while(cur->next != NULL) {
                prev = cur;
                cur = cur->next;
            }
            // Delete
            tail = prev;
            prev->next = NULL;
            delete cur;
        }

        // Delete at a particular position
        void delete_at_pos(int pos) {
            ListNode *prev, *cur;
            cur = head;
            for (int i = 1; i < pos; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
        }
};