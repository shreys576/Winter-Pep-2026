#include <bits/stdc++.h>
using namespace std;

/*
Sample input (t = number of test cases):
3
4
1 2 2 1
5
1 2 3 2 1
3
1 2 3

Expected output:
true
true
false
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

    ListNode* reverseNode(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode = NULL;

        while(curr != NULL){
            nextnode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;

    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow = reverseNode(slow);
        ListNode* p1 = head;
        ListNode* p2 = slow;

        while(p2){
            if(p1 -> val != p2 -> val){
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return true;
    }
};

// Helpers
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

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<int> vals(n);
        for(int i = 0; i < n; ++i) cin >> vals[i];
        ListNode* head = buildList(vals);
        Solution sol;
        bool ans = sol.isPalindrome(head);
        cout << (ans ? "true" : "false") << '\n';
        freeList(head);
    }
    return 0;
}
