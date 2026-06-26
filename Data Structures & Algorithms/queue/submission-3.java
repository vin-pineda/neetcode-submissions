class Node {
    
    int value;
    Node prev;
    Node next;

    public Node (int value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class Deque {
    private Node dummyHead;
    private Node dummyTail;

    public Deque() {
        this.dummyHead = new Node(0);
        this.dummyTail = new Node(0);
        
        this.dummyHead.next=this.dummyTail;
        this.dummyTail.prev=this.dummyHead;
    }

    public boolean isEmpty() {
        return this.dummyHead.next==this.dummyTail;
    }

    public void append(int value) {
       Node newNode = new Node(value);
       newNode.prev = this.dummyTail.prev;
       newNode.next = this.dummyTail;
       this.dummyTail.prev.next = newNode;
       this.dummyTail.prev = newNode;
    }

    public void appendleft(int value) {
        Node newNode = new Node(value);
        newNode.next = this.dummyHead.next;
        newNode.prev = this.dummyHead;
        this.dummyHead.next.prev = newNode;
        this.dummyHead.next = newNode;
    }

    public int pop() {
        if(isEmpty()) return -1;

        Node targetNode = this.dummyTail.prev;
        Node previous = targetNode.prev;
        int value = targetNode.value;

        this.dummyTail.prev = previous;
        previous.next = this.dummyTail;
        return value;
    }

    public int popleft() {
        if (isEmpty()) return -1;

        Node targetNode = this.dummyHead.next;
        Node next = targetNode.next;
        int value = targetNode.value;

        this.dummyHead.next = next;
        next.prev = this.dummyHead;
        return value;
    }
}
