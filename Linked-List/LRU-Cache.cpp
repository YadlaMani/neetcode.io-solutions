#include <map>
using namespace std;

class LRUCache {
public:
    // doubly linked list
    class Node {
    public:
        int key, val;
        Node *prev, *next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    // Map to store key-node pairs 
    map<int, Node*> mp;
    Node *head, *tail; // Dummy head and tail nodes for the doubly linked list
    int n; // Capacity of the cache

   
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1); // Dummy head node
        tail = new Node(-1, -1); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // Get the value of the key if it exists in the cache, otherwise return -1
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node *node = mp[key];
            removeNode(node); // Move accessed node to the front
            addNode(node);
            return node->val;
        }
        return -1; // Key not found
    }

    // Add a node right after the head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the doubly linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Put a key-value pair in the cache
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // If key is already present, update its value and move it to the front
            Node* node = mp[key];
            removeNode(node);
            node->val = value;
            addNode(node);
        } else {
            // If cache is full, remove the least recently used node
            if (mp.size() == n) {
                Node* nodeToRemove = tail->prev;
                removeNode(nodeToRemove);
                mp.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            // Add new node to the front and map it
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
