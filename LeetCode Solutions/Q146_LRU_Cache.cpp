#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node*> cache;
    int cap;

    Node* head;
    Node* tail;

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* left = node->prev;
        Node* right = node->next;

        left->next = right;
        right->prev = left;
    }

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        removeNode(node);
        addToFront(node);

        return node->value;
    }

    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {

            Node* node = cache[key];
            node->value = value;

            removeNode(node);
            addToFront(node);

            return;
        }
        if (cache.size() == cap) {

            Node* toDelete = tail->prev;

            cache.erase(toDelete->key);
            removeNode(toDelete);

            delete toDelete;
        }

        Node* newNode = new Node(key, value);

        cache[key] = newNode;
        addToFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    cout << "===== Test Case 1 (LeetCode Standard Example) =====\n";
    LRUCache cache1(2);

    cache1.put(1, 1);
    cache1.put(2, 2);

    cout << "get(1) = " << cache1.get(1) << " (Expected: 1)\n";

    cache1.put(3, 3); // evicts key 2
    cout << "get(2) = " << cache1.get(2) << " (Expected: -1)\n";

    cache1.put(4, 4); // evicts key 1
    cout << "get(1) = " << cache1.get(1) << " (Expected: -1)\n";
    cout << "get(3) = " << cache1.get(3) << " (Expected: 3)\n";
    cout << "get(4) = " << cache1.get(4) << " (Expected: 4)\n";

    cout << "\n===== Test Case 2 (Updating Existing Key) =====\n";
    LRUCache cache2(2);

    cache2.put(1, 10);
    cache2.put(2, 20);

    cout << "get(1) = " << cache2.get(1) << " (Expected: 10)\n";

    cache2.put(1, 99); // update value of key 1
    cout << "get(1) = " << cache2.get(1) << " (Expected: 99)\n";

    cache2.put(3, 30); // evicts key 2
    cout << "get(2) = " << cache2.get(2) << " (Expected: -1)\n";
    cout << "get(3) = " << cache2.get(3) << " (Expected: 30)\n";

    cout << "\n===== Test Case 3 (Capacity = 1) =====\n";
    LRUCache cache3(1);

    cache3.put(1, 100);
    cout << "get(1) = " << cache3.get(1) << " (Expected: 100)\n";

    cache3.put(2, 200); // evicts key 1
    cout << "get(1) = " << cache3.get(1) << " (Expected: -1)\n";
    cout << "get(2) = " << cache3.get(2) << " (Expected: 200)\n";

    cout << "\n===== Test Case 4 (Access changes LRU order) =====\n";
    LRUCache cache4(3);

    cache4.put(1, 1);
    cache4.put(2, 2);
    cache4.put(3, 3);

    cout << "get(1) = " << cache4.get(1) << " (Expected: 1)\n"; 
    // now LRU is key 2

    cache4.put(4, 4); // should evict key 2
    cout << "get(2) = " << cache4.get(2) << " (Expected: -1)\n";
    cout << "get(3) = " << cache4.get(3) << " (Expected: 3)\n";
    cout << "get(4) = " << cache4.get(4) << " (Expected: 4)\n";

    cout << "\n===== Test Case 5 (Get non-existing key) =====\n";
    LRUCache cache5(2);

    cout << "get(99) = " << cache5.get(99) << " (Expected: -1)\n";

    return 0;
}