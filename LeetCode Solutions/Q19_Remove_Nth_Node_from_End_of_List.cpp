#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }

        if(fast == NULL) return head -> next;

        while(fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next; 
        }

        ListNode* toDel = slow -> next;
        slow -> next = toDel -> next;
        delete toDel;
        return head;
    }
};

// Helpers
ListNode* createList(const std::vector<int>& vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for(size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head) {
    if(!head) {
        std::cout << "Empty list\n";
        return;
    }
    while(head) {
        std::cout << head->val;
        if(head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << '\n';
}

void freeList(ListNode* head) {
    while(head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    // Sample 1: remove 2nd from end from 1->2->3->4->5 (expect 1->2->3->5)
    ListNode* h1 = createList({1,2,3,4,5});
    std::cout << "Input 1: "; printList(h1);
    ListNode* r1 = sol.removeNthFromEnd(h1, 2);
    std::cout << "After removing 2nd from end: "; printList(r1);
    freeList(r1);
    std::cout << "---\n";

    // Sample 2: remove head when n == length (remove 1 from [1]) -> Empty
    ListNode* h2 = createList({1});
    std::cout << "Input 2: "; printList(h2);
    ListNode* r2 = sol.removeNthFromEnd(h2, 1);
    std::cout << "After removing 1st from end: "; printList(r2);
    freeList(r2);
    std::cout << "---\n";

    // Sample 3: remove head from longer list (n == length)
    ListNode* h3 = createList({10,20,30,40});
    std::cout << "Input 3: "; printList(h3);
    ListNode* r3 = sol.removeNthFromEnd(h3, 4);
    std::cout << "After removing 4th from end: "; printList(r3);
    freeList(r3);

    return 0;
}
