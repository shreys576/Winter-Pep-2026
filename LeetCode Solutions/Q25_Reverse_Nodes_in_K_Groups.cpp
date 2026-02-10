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

    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;
        ListNode* temp3 = temp2 -> next;
        temp1 -> next = NULL;
        while(temp2 != NULL){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            if(temp3 != NULL){
                temp3 = temp3 -> next;
            }
        }
        return temp1;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        ListNode* tempcount = head;
        ListNode* prev = dummy;
        int count = 0;
        while(tempcount != NULL){
            count++;
            tempcount = tempcount -> next;
        }
        ListNode* temp = head;
        while(count >= k){
            ListNode* temphead = temp;
            for(int i = 1; i < k; i++){
                temp = temp -> next;
            }
            ListNode* cont = temp -> next;
            temp -> next = NULL;
            temp = cont;
            ListNode* reversehead = reverse(temphead);
            prev -> next = reversehead;
            temphead -> next = temp;
            prev = temphead;
            count -= k;
        }
        prev -> next = temp;
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
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = createList(arr1);

    cout << "Input List: ";
    printList(head1);
    cout << "k = " << k1 << endl;

    ListNode* result1 = sol.reverseKGroup(head1, k1);

    cout << "Output List: ";
    printList(result1);
    cout << "Expected: 2 -> 1 -> 4 -> 3 -> 5\n\n";


    cout << "===== Test Case 2 =====\n";
    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    ListNode* head2 = createList(arr2);

    cout << "Input List: ";
    printList(head2);
    cout << "k = " << k2 << endl;

    ListNode* result2 = sol.reverseKGroup(head2, k2);

    cout << "Output List: ";
    printList(result2);
    cout << "Expected: 3 -> 2 -> 1 -> 4 -> 5\n\n";


    cout << "===== Test Case 3 =====\n";
    vector<int> arr3 = {1, 2, 3, 4, 5, 6};
    int k3 = 3;
    ListNode* head3 = createList(arr3);

    cout << "Input List: ";
    printList(head3);
    cout << "k = " << k3 << endl;

    ListNode* result3 = sol.reverseKGroup(head3, k3);

    cout << "Output List: ";
    printList(result3);
    cout << "Expected: 3 -> 2 -> 1 -> 6 -> 5 -> 4\n\n";


    cout << "===== Test Case 4 =====\n";
    vector<int> arr4 = {1, 2, 3};
    int k4 = 5;
    ListNode* head4 = createList(arr4);

    cout << "Input List: ";
    printList(head4);
    cout << "k = " << k4 << endl;

    ListNode* result4 = sol.reverseKGroup(head4, k4);

    cout << "Output List: ";
    printList(result4);
    cout << "Expected: 1 -> 2 -> 3 (no change)\n\n";


    cout << "===== Test Case 5 =====\n";
    vector<int> arr5 = {1, 2, 3, 4};
    int k5 = 1;
    ListNode* head5 = createList(arr5);

    cout << "Input List: ";
    printList(head5);
    cout << "k = " << k5 << endl;

    ListNode* result5 = sol.reverseKGroup(head5, k5);

    cout << "Output List: ";
    printList(result5);
    cout << "Expected: 1 -> 2 -> 3 -> 4 (no change)\n\n";


    cout << "===== Test Case 6 (Empty List) =====\n";
    vector<int> arr6 = {};
    int k6 = 3;
    ListNode* head6 = createList(arr6);

    cout << "Input List: ";
    printList(head6);
    cout << "k = " << k6 << endl;

    ListNode* result6 = sol.reverseKGroup(head6, k6);

    cout << "Output List: ";
    printList(result6);
    cout << "Expected: (empty)\n\n";

    return 0;
}