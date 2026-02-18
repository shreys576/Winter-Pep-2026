#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            int tempVal = l1 -> val + l2 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL){
            int tempVal = l1 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL){
            int tempVal = l2 -> val + carry;
            carry = 0;
            if(tempVal >= 10){
                carry = tempVal / 10;
                tempVal = tempVal % 10;
            }
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
            l2 = l2 -> next;
        }

        while(carry != 0){
            int tempVal = carry;
            if(tempVal >= 10){
                tempVal = tempVal % 10;
            }
            carry = carry - tempVal;
            ListNode* newnode = new ListNode(tempVal);
            ptr -> next = newnode;
            ptr = ptr -> next;
        }
        return dummy -> next;
    }
};

// Helper: create linked list from vector
ListNode* createList(vector<int> v) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    for(int x : v) {
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    return dummy->next;
}

// Helper: print linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // 342 + 465 = 807
    // l1 = [2,4,3], l2 = [5,6,4]
    ListNode* l1 = createList({2,4,3});
    ListNode* l2 = createList({5,6,4});

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* ans1 = sol.addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(ans1);
    cout << "Expected: 7 -> 0 -> 8\n\n";


    cout << "===== Test Case 2 =====\n";
    // 0 + 0 = 0
    ListNode* l3 = createList({0});
    ListNode* l4 = createList({0});

    cout << "List 1: ";
    printList(l3);
    cout << "List 2: ";
    printList(l4);

    ListNode* ans2 = sol.addTwoNumbers(l3, l4);
    cout << "Result: ";
    printList(ans2);
    cout << "Expected: 0\n\n";


    cout << "===== Test Case 3 =====\n";
    // 9999999 + 9999 = 10009998
    // l1 = [9,9,9,9,9,9,9]
    // l2 = [9,9,9,9]
    ListNode* l5 = createList({9,9,9,9,9,9,9});
    ListNode* l6 = createList({9,9,9,9});

    cout << "List 1: ";
    printList(l5);
    cout << "List 2: ";
    printList(l6);

    ListNode* ans3 = sol.addTwoNumbers(l5, l6);
    cout << "Result: ";
    printList(ans3);
    cout << "Expected: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1\n\n";


    cout << "===== Test Case 4 =====\n";
    // 81 + 0 = 81
    // l1 = [1,8], l2 = [0]
    ListNode* l7 = createList({1,8});
    ListNode* l8 = createList({0});

    cout << "List 1: ";
    printList(l7);
    cout << "List 2: ";
    printList(l8);

    ListNode* ans4 = sol.addTwoNumbers(l7, l8);
    cout << "Result: ";
    printList(ans4);
    cout << "Expected: 1 -> 8\n\n";


    cout << "===== Test Case 5 =====\n";
    // 95 + 7 = 102
    // l1 = [5,9], l2 = [7]
    ListNode* l9 = createList({5,9});
    ListNode* l10 = createList({7});

    cout << "List 1: ";
    printList(l9);
    cout << "List 2: ";
    printList(l10);

    ListNode* ans5 = sol.addTwoNumbers(l9, l10);
    cout << "Result: ";
    printList(ans5);
    cout << "Expected: 2 -> 0 -> 1\n\n";

    return 0;
}
