#include <bits/stdc++.h>
using namespace std;

// LeetCode 160 - Intersection of Two Linked Lists
// Provided Solution with runnable main() which constructs two lists that intersect

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0;
        int lb = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){
            la++;
            tempA = tempA -> next;
        }
        ListNode* tempB = headB;
        while(tempB != NULL){
            lb++;
            tempB = tempB -> next;
        }
        int mini = min(la, lb);
        int fa = la - mini;
        for(int i = 0; i < fa; i++){
            headA = headA -> next;
        }
        int fb = lb - mini;
        for(int i = 0; i < fb; i++){
            headB = headB -> next;
        }
        tempA = headA;
        tempB = headB;
        for(int i = 0; i < mini; i++){
            if(tempA == tempB) return tempA;
            else{
                tempA = tempA -> next;
                tempB = tempB -> next;
            }
        }
        return NULL;
    }
};

// Helpers to create and print lists
ListNode* make_list(const vector<int>& vals) {
    if(vals.empty()) return NULL;
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
    // Construct shared tail: 8 -> 4 -> 5
    ListNode* shared = make_list({8,4,5});

    // List A: 4 -> 1 -> [shared]
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = shared;

    // List B: 5 -> 6 -> 1 -> [shared]
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = shared;

    cout << "List A: "; print_list(headA);
    cout << "List B: "; print_list(headB);

    Solution sol;
    ListNode* inter = sol.getIntersectionNode(headA, headB);
    if(inter) cout << "Intersection at node with value: " << inter->val << '\n';
    else cout << "No intersection\n";

    return 0;
}
