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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesser = new ListNode(0);
        ListNode* greater = new ListNode(0);

        ListNode* less = lesser;
        ListNode* great = greater;

        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> val < x){
                less -> next = temp;
                less = less -> next;
            }
            else{
                great -> next = temp;
                great = great -> next;
            }
            temp = temp -> next;
        }
        great -> next = NULL;
        less -> next = greater -> next;
        return lesser -> next;
    }
};

// Helper function: create linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function: print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val;
        if(temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    ListNode* head1 = createList(arr1);

    cout << "Test Case 1:\n";
    cout << "Input List: ";
    printList(head1);
    cout << "x = " << x1 << endl;

    ListNode* result1 = sol.partition(head1, x1);
    cout << "Output List: ";
    printList(result1);
    cout << "\n";


    // Test Case 2
    vector<int> arr2 = {2, 1};
    int x2 = 2;
    ListNode* head2 = createList(arr2);

    cout << "Test Case 2:\n";
    cout << "Input List: ";
    printList(head2);
    cout << "x = " << x2 << endl;

    ListNode* result2 = sol.partition(head2, x2);
    cout << "Output List: ";
    printList(result2);
    cout << "\n";


    // Test Case 3
    vector<int> arr3 = {3, 1, 2};
    int x3 = 3;
    ListNode* head3 = createList(arr3);

    cout << "Test Case 3:\n";
    cout << "Input List: ";
    printList(head3);
    cout << "x = " << x3 << endl;

    ListNode* result3 = sol.partition(head3, x3);
    cout << "Output List: ";
    printList(result3);
    cout << "\n";


    // Test Case 4 (all elements smaller than x)
    vector<int> arr4 = {1, 1, 1, 1};
    int x4 = 5;
    ListNode* head4 = createList(arr4);

    cout << "Test Case 4:\n";
    cout << "Input List: ";
    printList(head4);
    cout << "x = " << x4 << endl;

    ListNode* result4 = sol.partition(head4, x4);
    cout << "Output List: ";
    printList(result4);
    cout << "\n";


    // Test Case 5 (all elements greater than or equal to x)
    vector<int> arr5 = {6, 7, 8, 9};
    int x5 = 5;
    ListNode* head5 = createList(arr5);

    cout << "Test Case 5:\n";
    cout << "Input List: ";
    printList(head5);
    cout << "x = " << x5 << endl;

    ListNode* result5 = sol.partition(head5, x5);
    cout << "Output List: ";
    printList(result5);
    cout << "\n";


    // Test Case 6 (single node)
    vector<int> arr6 = {10};
    int x6 = 5;
    ListNode* head6 = createList(arr6);

    cout << "Test Case 6:\n";
    cout << "Input List: ";
    printList(head6);
    cout << "x = " << x6 << endl;

    ListNode* result6 = sol.partition(head6, x6);
    cout << "Output List: ";
    printList(result6);
    cout << "\n";


    // Test Case 7 (empty list)
    vector<int> arr7 = {};
    int x7 = 3;
    ListNode* head7 = createList(arr7);

    cout << "Test Case 7:\n";
    cout << "Input List: ";
    printList(head7);
    cout << "x = " << x7 << endl;

    ListNode* result7 = sol.partition(head7, x7);
    cout << "Output List: ";
    printList(result7);
    cout << "\n";

    return 0;
}