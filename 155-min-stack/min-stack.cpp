class MinStack {
private:
    struct Node {
        int val;
        int minSoFar;
        Node* next;

        Node(int v, int m, Node* n = nullptr)
            : val(v)
            , minSoFar(m)
            , next(n)
        { }
    };

    Node* head;

public:
    MinStack() : head(nullptr) { }

    ~MinStack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push(int val) {
        if (!head) {
            head = new Node(val, val);
        } else {
            int currentMin = min(val, head->minSoFar);
            head = new Node(val, currentMin, head);
        }
    }
    
    void pop() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->minSoFar;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */