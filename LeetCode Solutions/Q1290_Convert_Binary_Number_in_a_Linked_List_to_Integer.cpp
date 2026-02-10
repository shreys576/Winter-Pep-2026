#include <bits/stdc++.h>
using namespace std;

// LeetCode 1290 - Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        int fin = 0;
        temp = head;
        while(temp != 0){
            if(temp -> val == 1){
                fin += (int)pow(2, count - 1);
            }
            temp = temp -> next;
            count--;
        }
        return fin;
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
    // Sample input: binary list 1 -> 0 -> 1 -> 1 (which is 11 in decimal)
    vector<int> sample = {1, 0, 1, 1};
    ListNode* head = make_list(sample);

    cout << "Binary list: ";
    print_list(head);

    Solution sol;
    int value = sol.getDecimalValue(head);

    cout << "Decimal value: " << value << '\n';
    return 0;
}
