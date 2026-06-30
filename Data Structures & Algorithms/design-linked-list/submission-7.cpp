class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node(int v, Node* p = nullptr, Node* n = nullptr) : val(v), prev(p), next(n) {};
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    Node* getPrev(int index) {
        Node* cur;
        if (index <= size / 2) {
            cur = head;
            for (int i = 0; i < index; i++) cur = cur->next;
            return cur;
        }
        cur = tail;
        for (int i = 0; i <= size - index; i++) cur = cur->prev;
        return cur;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        return getPrev(index)->next->val;
    }
    
    void addAtHead(int val) {addAtIndex(0, val);}
    
    void addAtTail(int val) {addAtIndex(size, val);}
    
    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if( index > size) return;
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
        if (index < 0 || index >= size) return;
        Node* prev = getPrev(index);
        Node* cur = prev->next;
        Node* next = cur->next;
        prev->next = next;
        next->prev = prev;
        delete cur;
        size--;
    }
};