class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v, Node* n = nullptr, Node* p = nullptr) : val(v), next(n), prev(p) {};
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    Node* getPrev (int index) {
        if (index <= size / 2) {
            Node* cur = head;
            for(int i  = 0; i < index; i++) cur = cur->next; return cur;
        }
        Node* cur = tail;
        for(int i = 0; i <= size - index; i++) cur = cur->prev; return cur;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        return getPrev(index)->next->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;
        Node* node = new Node(val);
        Node* prev = getPrev(index);
        Node* next = prev->next;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        Node* prev = getPrev(index);
        Node* cur = prev->next;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        size--;
    }
};