struct Node {
    string val;
    Node* prev;
    Node* next;
    Node (string v, Node* p = nullptr, Node* n = nullptr) : val(v), prev(p), next(n) {};
};

class BrowserHistory {
    Node* current;
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        current->next = new Node(url, current);
        current = current->next;
    }
    
    string back(int steps) {
        while (current->prev && steps > 0) {
            current = current->prev;
            steps--;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while (current->next && steps > 0) {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */