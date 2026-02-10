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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        while(head != nullptr && head -> val == val){
            ListNode* toDel = head;
            head = head -> next;
            delete toDel;
        }
        ListNode* temp = head;
        while(temp != nullptr && temp -> next != nullptr){
            if(temp -> next -> val == val){
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

    // Sample 1: mixed, remove 6
    ListNode* h1 = createList({1,2,6,3,4,5,6});
    std::cout << "Input 1: "; printList(h1);
    ListNode* r1 = sol.removeElements(h1, 6);
    std::cout << "After removing 6: "; printList(r1);
    freeList(r1);
    std::cout << "---\n";

    // Sample 2: empty list
    ListNode* h2 = createList({});
    std::cout << "Input 2: "; printList(h2);
    ListNode* r2 = sol.removeElements(h2, 1);
    std::cout << "After removing 1: "; printList(r2);
    freeList(r2);
    std::cout << "---\n";

    // Sample 3: all elements equal to val
    ListNode* h3 = createList({7,7,7,7});
    std::cout << "Input 3: "; printList(h3);
    ListNode* r3 = sol.removeElements(h3, 7);
    std::cout << "After removing 7: "; printList(r3);
    freeList(r3);
    std::cout << "---\n";

    // Sample 4: no elements equal to val
    ListNode* h4 = createList({1,2,3,4,5});
    std::cout << "Input 4: "; printList(h4);
    ListNode* r4 = sol.removeElements(h4, 6);
    std::cout << "After removing 6: "; printList(r4);
    freeList(r4);

    return 0;
}
