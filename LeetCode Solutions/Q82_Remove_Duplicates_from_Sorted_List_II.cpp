#include <bits/stdc++.h>
using namespace std;

// LeetCode 82 - Remove Duplicates from Sorted List II
// Provided Solution with a runnable main() and sample input

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr != NULL){
            if( curr -> next != NULL && curr -> val == curr -> next -> val){
                int value = curr -> val;
                while(curr != NULL && curr-> val == value){
                    ListNode* toDel = curr;
                    curr = curr -> next;
                    delete toDel;
                }
                prev -> next = curr;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return dummy -> next;
    }
};

// Helpers
ListNode* make_list(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for(size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void print_list(ListNode* head) {
    ListNode* cur = head;
    while(cur) {
        cout << cur->val;
        if(cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << '\n';
}

int main() {
    // Sample input: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    vector<int> sample = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = make_list(sample);

    cout << "Original: ";
    print_list(head);

    Solution sol;
    ListNode* res = sol.deleteDuplicates(head);

    cout << "After removing duplicates: ";
    print_list(res);

    return 0;
}
