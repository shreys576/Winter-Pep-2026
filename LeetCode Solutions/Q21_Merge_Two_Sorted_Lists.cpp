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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 -> val < temp2 -> val){
                prev -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                prev -> next = temp2;
                temp2 = temp2 -> next;
            }
            prev = prev -> next;
        }
        while(temp1 != NULL){
            prev -> next = temp1;
            temp1 = temp1 -> next;
            prev = prev -> next;
        }    
        while(temp2 != NULL){
            prev -> next = temp2;
            temp2 = temp2 -> next;
            prev = prev -> next;
        }
        return dummy -> next;
    }
};

// Helper: Create linked list from vector
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

// Helper: Print linked list
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

    cout << "===== Test Case 1 =====\n";
    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    ListNode* list1 = createList(arr1);
    ListNode* list2 = createList(arr2);

    cout << "List1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);

    ListNode* merged1 = sol.mergeTwoLists(list1, list2);

    cout << "Merged: ";
    printList(merged1);
    cout << "Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4\n\n";


    cout << "===== Test Case 2 (One Empty List) =====\n";
    vector<int> arr3 = {};
    vector<int> arr4 = {0};

    ListNode* list3 = createList(arr3);
    ListNode* list4 = createList(arr4);

    cout << "List1: ";
    printList(list3);
    cout << "List2: ";
    printList(list4);

    ListNode* merged2 = sol.mergeTwoLists(list3, list4);

    cout << "Merged: ";
    printList(merged2);
    cout << "Expected: 0\n\n";


    cout << "===== Test Case 3 (Both Empty Lists) =====\n";
    vector<int> arr5 = {};
    vector<int> arr6 = {};

    ListNode* list5 = createList(arr5);
    ListNode* list6 = createList(arr6);

    cout << "List1: ";
    printList(list5);
    cout << "List2: ";
    printList(list6);

    ListNode* merged3 = sol.mergeTwoLists(list5, list6);

    cout << "Merged: ";
    printList(merged3);
    cout << "Expected: (empty)\n\n";


    cout << "===== Test Case 4 =====\n";
    vector<int> arr7 = {2, 5, 7};
    vector<int> arr8 = {1, 3, 4, 6};

    ListNode* list7 = createList(arr7);
    ListNode* list8 = createList(arr8);

    cout << "List1: ";
    printList(list7);
    cout << "List2: ";
    printList(list8);

    ListNode* merged4 = sol.mergeTwoLists(list7, list8);

    cout << "Merged: ";
    printList(merged4);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7\n\n";

    return 0;
}
