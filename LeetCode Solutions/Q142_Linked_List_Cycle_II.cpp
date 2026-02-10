#include <bits/stdc++.h>
using namespace std;

// LeetCode 142 - Linked List Cycle II
// Provided Solution with a runnable main() that constructs a cyclic list

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast){
                ListNode* intersect = slow;
                slow = head;
                while(slow != intersect){
                    slow = slow -> next;
                    intersect = intersect -> next;
                }
            return intersect;
            }
        }
        return NULL;
    }
};

// Build a list from vals and create a cycle connecting tail to index `pos` (-1 = no cycle)
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
    // Sample: [3,2,0,-4] with tail connecting to index 1 (node with value 2)
    vector<int> vals = {3, 2, 0, -4};
    int pos = 1; // cycle starts at node with value 2
    ListNode* head = make_list_with_cycle(vals, pos);

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);
    
    if(cycleStart != NULL) {
        cout << "Cycle detected at node with value: " << cycleStart->val << '\n';
    } else {
        cout << "No cycle detected\n";
    }

    return 0;
}
