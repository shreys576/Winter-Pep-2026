#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* temp = head;
        Node* prev = head;
        while(temp != NULL){
            temp = temp-> next;
            Node* tempnode = new Node(prev -> val);
            tempnode -> next = temp;
            prev -> next = tempnode;
            prev = temp;
        }
        temp = head;
        while(temp != NULL){
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        Node* dummy = new Node(0);
        Node* dhead = dummy;
        temp = head;
        while(temp != NULL){
            dhead -> next = temp -> next;
            dhead = dhead -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};

// Helper function to print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << "Node(" << temp->val << ")";

        if(temp->random != NULL)
            cout << " Random->(" << temp->random->val << ")";
        else
            cout << " Random->(NULL)";

        cout << endl;
        temp = temp->next;
    }
}

// Helper: create list from values and random mapping
Node* createRandomList(vector<int> vals, vector<int> randomIndex) {
    int n = vals.size();
    if(n == 0) return NULL;

    vector<Node*> nodes(n);

    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(vals[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    for(int i = 0; i < n; i++) {
        if(randomIndex[i] != -1) {
            nodes[i]->random = nodes[randomIndex[i]];
        }
    }

    return nodes[0];
}

int main() {
    Solution sol;

    cout << "===== Test Case 1 =====\n";
    // Example: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    vector<int> vals1 = {7, 13, 11, 10, 1};
    vector<int> random1 = {-1, 0, 4, 2, 0};
    Node* head1 = createRandomList(vals1, random1);

    cout << "Original List:\n";
    printList(head1);

    Node* copied1 = sol.copyRandomList(head1);

    cout << "\nCopied List:\n";
    printList(copied1);
    cout << "\n";


    cout << "===== Test Case 2 =====\n";
    // Example: [[1,1],[2,1]]
    vector<int> vals2 = {1, 2};
    vector<int> random2 = {1, 1};
    Node* head2 = createRandomList(vals2, random2);

    cout << "Original List:\n";
    printList(head2);

    Node* copied2 = sol.copyRandomList(head2);

    cout << "\nCopied List:\n";
    printList(copied2);
    cout << "\n";


    cout << "===== Test Case 3 =====\n";
    // Example: [[3,null],[3,0],[3,null]]
    vector<int> vals3 = {3, 3, 3};
    vector<int> random3 = {-1, 0, -1};
    Node* head3 = createRandomList(vals3, random3);

    cout << "Original List:\n";
    printList(head3);

    Node* copied3 = sol.copyRandomList(head3);

    cout << "\nCopied List:\n";
    printList(copied3);
    cout << "\n";


    cout << "===== Test Case 4 (Empty List) =====\n";
    Node* head4 = NULL;

    cout << "Original List: NULL\n";
    Node* copied4 = sol.copyRandomList(head4);

    if(copied4 == NULL) {
        cout << "Copied List: NULL (Expected)\n";
    }

    return 0;
}
