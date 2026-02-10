#include <bits/stdc++.h>
using namespace std;

// LeetCode 206 - Reverse Linked List
// Sample runnable C++ implementation with a test in main()

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        if(head -> next == nullptr) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;
        temp1 -> next = nullptr;
        while(temp2 -> next != nullptr){
            ListNode* temp3 = temp2 -> next;
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        temp2 -> next = temp1;
        return temp2;
    }
};

// Helpers to build and print linked lists for testing
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
    // Sample input: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> sample = {1, 2, 3, 4, 5};
    ListNode* head = make_list(sample);

    cout << "Original: ";
    print_list(head);

    Solution sol;
    ListNode* rev = sol.reverseList(head);

    cout << "Reversed: ";
    print_list(rev);

    return 0;
}
