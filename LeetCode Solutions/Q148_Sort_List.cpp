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
    ListNode* getMiddle(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* leftHalf, ListNode* rightHalf){
        ListNode dummy(0);
        ListNode* dummy1 = &dummy;
        while(leftHalf && rightHalf){
            if(leftHalf->val < rightHalf->val){
                dummy1->next = leftHalf;
                leftHalf = leftHalf->next;
            }else{
                dummy1->next = rightHalf;
                rightHalf = rightHalf->next;
            }

            dummy1 = dummy1->next;
        }

        if(leftHalf != nullptr) dummy1->next = leftHalf;

        if(rightHalf != nullptr) dummy1->next = rightHalf;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        // Disconnecting the left half and right half
        mid->next = nullptr;

        ListNode* leftHalf = sortList(left);
        ListNode* rightHalf = sortList(right);

        return merge(leftHalf, rightHalf);
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
    vector<int> arr1 = {4, 2, 1, 3};
    ListNode* head1 = createList(arr1);

    cout << "Input List: ";
    printList(head1);

    ListNode* result1 = sol.sortList(head1);

    cout << "Sorted List: ";
    printList(result1);
    cout << "Expected: 1 -> 2 -> 3 -> 4\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> arr2 = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(arr2);

    cout << "Input List: ";
    printList(head2);

    ListNode* result2 = sol.sortList(head2);

    cout << "Sorted List: ";
    printList(result2);
    cout << "Expected: -1 -> 0 -> 3 -> 4 -> 5\n\n";


    cout << "===== Test Case 3 (Already Sorted) =====\n";
    vector<int> arr3 = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(arr3);

    cout << "Input List: ";
    printList(head3);

    ListNode* result3 = sol.sortList(head3);

    cout << "Sorted List: ";
    printList(result3);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5\n\n";


    cout << "===== Test Case 4 (Reverse Sorted) =====\n";
    vector<int> arr4 = {5, 4, 3, 2, 1};
    ListNode* head4 = createList(arr4);

    cout << "Input List: ";
    printList(head4);

    ListNode* result4 = sol.sortList(head4);

    cout << "Sorted List: ";
    printList(result4);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5\n\n";


    cout << "===== Test Case 5 (Duplicates) =====\n";
    vector<int> arr5 = {4, 2, 2, 4, 1, 3, 3};
    ListNode* head5 = createList(arr5);

    cout << "Input List: ";
    printList(head5);

    ListNode* result5 = sol.sortList(head5);

    cout << "Sorted List: ";
    printList(result5);
    cout << "Expected: 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4\n\n";


    cout << "===== Test Case 6 (Single Node) =====\n";
    vector<int> arr6 = {10};
    ListNode* head6 = createList(arr6);

    cout << "Input List: ";
    printList(head6);

    ListNode* result6 = sol.sortList(head6);

    cout << "Sorted List: ";
    printList(result6);
    cout << "Expected: 10\n\n";


    cout << "===== Test Case 7 (Empty List) =====\n";
    vector<int> arr7 = {};
    ListNode* head7 = createList(arr7);

    cout << "Input List: ";
    printList(head7);

    ListNode* result7 = sol.sortList(head7);

    cout << "Sorted List: ";
    printList(result7);
    cout << "Expected: (empty)\n\n";

    return 0;
}
