struct Node {
    int val;
    Node* prev;
    Node* next;
    Node (int v, Node* p = nullptr, Node* n = nullptr) : val(v), prev(p), next(n) {};
};

class Deque {
private:
    Node* dummyHead;
    Node* dummyTail;

public:
    Deque() {
        dummyHead = new Node(0);
        dummyTail = new Node(0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {return dummyHead->next == dummyTail;}

    void append(int value) {
        Node* node = new Node(value);
        Node* prev = dummyTail->prev;

        node->next = dummyTail;
        node->prev = prev;

        prev->next = node;
        dummyTail->prev = node;
    }

    void appendleft(int value) {
        Node* node = new Node(value);
        Node* next = dummyHead->next;

        node->prev = dummyHead;
        node->next = next;

        next->prev = node;
        dummyHead->next = node;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* node = dummyTail->prev;
        Node* prevNode = node->prev;
        int value = node->val;
        prevNode->next = dummyTail;
        dummyTail->prev = prevNode;
        delete node;
        return value;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node* node = dummyHead->next;
        Node* nextNode = node->next;
        int value = node->val;
        nextNode->prev = dummyHead;
        dummyHead->next = nextNode;
        delete node;
        return value;
    }
};
