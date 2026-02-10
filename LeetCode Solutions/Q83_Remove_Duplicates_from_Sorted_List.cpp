#include <bits/stdc++.h>
using namespace std;

/*
Sample input (first line n = number of nodes, then n values):
7
1 1 2 3 3 4 5

Expected output:
1 2 3 4 5
*/

// Definition for singly-linked list.
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
        if(head == nullptr) return head;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            if(temp -> val == temp -> next -> val){
                ListNode* toDel = temp -> next;
                temp -> next = toDel -> next;
                delete toDel;
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
};

// Helper: build list from vector
ListNode* buildList(const vector<int>& vals){
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for(size_t i = 1; i < vals.size(); ++i){
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// Helper: print list
void printList(ListNode* head){
    ListNode* cur = head;
    bool first = true;
    while(cur){
        if(!first) cout << " ";
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << '\n';
}

// Helper: free list
void freeList(ListNode* head){
    while(head){
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0; // no input
    vector<int> vals(n);
    for(int i = 0; i < n; ++i) cin >> vals[i];

    ListNode* head = buildList(vals);
    Solution sol;
    head = sol.deleteDuplicates(head);
    printList(head);
    freeList(head);
    return 0;
}
