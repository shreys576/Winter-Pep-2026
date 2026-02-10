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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            count ++;
            temp = temp -> next;
        }
        int mid;
        if(count % 2 == 0){
            mid = (count / 2) + 1;
        }
        else{
            mid = (count / 2) + 1;
        }
        ListNode* m = head;
        for(int i = 1; i < mid; i++){
            m = m -> next;
        }
        return m;
    }
};

// Helper: create list from vector
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

// Helper: print list
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

int main() {
    Solution sol;

    // Sample case 1: odd-length list
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    std::cout << "Input 1: "; printList(head1);
    ListNode* mid1 = sol.middleNode(head1);
    std::cout << "Middle node onwards: "; printList(mid1);
    std::cout << "---\n";

    // Sample case 2: even-length list
    ListNode* head2 = createList({1, 2, 3, 4, 5, 6});
    std::cout << "Input 2: "; printList(head2);
    ListNode* mid2 = sol.middleNode(head2);
    std::cout << "Middle node onwards: "; printList(mid2);
    std::cout << "---\n";

    // Sample case 3: single node
    ListNode* head3 = createList({10});
    std::cout << "Input 3: "; printList(head3);
    ListNode* mid3 = sol.middleNode(head3);
    std::cout << "Middle node onwards: "; printList(mid3);

    return 0;
}
