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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenhead = even;
        while(odd -> next != NULL && even -> next != NULL){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = evenhead;
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

    // Sample 1: odd-even rearrangement on 6-element list
    ListNode* h1 = createList({1, 2, 3, 4, 5, 6});
    std::cout << "Input 1: "; printList(h1);
    ListNode* r1 = sol.oddEvenList(h1);
    std::cout << "After odd-even rearrange: "; printList(r1);
    freeList(r1);
    std::cout << "---\n";

    // Sample 2: 5-element list (odd count)
    ListNode* h2 = createList({1, 2, 3, 4, 5});
    std::cout << "Input 2: "; printList(h2);
    ListNode* r2 = sol.oddEvenList(h2);
    std::cout << "After odd-even rearrange: "; printList(r2);
    freeList(r2);
    std::cout << "---\n";

    // Sample 3: single element
    ListNode* h3 = createList({1});
    std::cout << "Input 3: "; printList(h3);
    ListNode* r3 = sol.oddEvenList(h3);
    std::cout << "After odd-even rearrange: "; printList(r3);
    freeList(r3);
    std::cout << "---\n";

    // Sample 4: two elements
    ListNode* h4 = createList({1, 2});
    std::cout << "Input 4: "; printList(h4);
    ListNode* r4 = sol.oddEvenList(h4);
    std::cout << "After odd-even rearrange: "; printList(r4);
    freeList(r4);

    return 0;
}
