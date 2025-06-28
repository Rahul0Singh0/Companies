#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move given node to front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Remove the least recently used node (from tail)
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lru = popTail();
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};


int main() {
    LRUCache lru(2); // Capacity = 2

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // returns 1

    lru.put(3, 3); // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)

    lru.put(4, 4); // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 3
    cout << lru.get(4) << endl; // returns 4

    return 0;
}