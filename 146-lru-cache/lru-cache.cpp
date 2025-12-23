class LRUCache {
public:
    // For Doubly Linked List
    class Node {
        public:

        int key, value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;

            prev = nullptr;
            next = nullptr;
        }
    };

    // Defining head & tail of DLL
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap; // capacity
    unordered_map<int, Node*> mp; // for O(1) operations

    void addNode(Node* newNode) {
        Node* temp = head->next;

        newNode->prev = head;
        newNode->next = temp;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* omitNode) {
        Node* prevNode = omitNode->prev;
        Node* nextNode = omitNode->next;

        prevNode->next =  nextNode;
        nextNode->prev = prevNode;
    }



    LRUCache(int capacity) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        cap = capacity;

        // DLL initialization
        head->next = tail;
        tail->prev = head;
    }
    
    /*
    if key found,
        get the corresponding node using hashmap
        collect the value from the node
        place the node from its currrent position to after-head position
        return the value
    else
        retur -1
    */
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* currNode = mp[key];
            int answer = currNode->value;
 
            deleteNode(currNode);
            addNode(currNode);
            mp[key] = head->next;

            return answer;
        }
        else return -1;
    }
    
    /*
    If key exists, 
        find corresponding node from hashmap
        delete the node
        add a node after the head with latest value
        update the hashmap with latest key-value
    else if the capacity is full,
        delete last node
        delete its entry from hashmap
        add a node after the head with latest value
        update the hashmap with latest key-value
    else,
        add a node after the head with latest value
        update the hashmap with latest key-value 
    */
    void put(int key, int value) {
        Node* currNode;
        if(mp.find(key) != mp.end()) { // key found, update it 
            currNode = mp[key];
            deleteNode(currNode);
        }
        else if(mp.size() == cap) { // fully loaded, update it with least recently used key
            currNode = tail->prev;
            mp.erase(currNode->key);
            deleteNode(currNode);
        }

        delete currNode;

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */