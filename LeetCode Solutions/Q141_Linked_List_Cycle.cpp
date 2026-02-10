#include <bits/stdc++.h>
using namespace std;

// LeetCode 141 (labeled Q14 here) - Linked List Cycle
// Provided Solution with a runnable main() that constructs a cycle for testing

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

// Build a list from vals and create a cycle connecting tail to index `pos` (-1 = no cycle).
ListNode* make_list_with_cycle(const vector<int>& vals, int pos) {
    if(vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    vector<ListNode*> nodes;
    nodes.push_back(head);
    for(size_t i = 1; i < vals.size(); ++i){
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
        nodes.push_back(cur);
    }
    if(pos >= 0 && pos < (int)nodes.size()){
        cur->next = nodes[pos];
    }
    return head;
}

int main(){
    // Sample: [3,2,0,-4] with tail connecting to index 1 -> cycle exists
    vector<int> vals = {3,2,0,-4};
    int pos = 1; // tail connects to node with value 2
    ListNode* head = make_list_with_cycle(vals, pos);

    Solution sol;
    bool has = sol.hasCycle(head);
    cout << (has ? "Has cycle: true\n" : "Has cycle: false\n");

    return 0;
}
