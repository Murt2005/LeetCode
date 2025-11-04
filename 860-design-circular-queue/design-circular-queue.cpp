class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (size == capacity) {
            return false;
        }

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) {
            return false;
        }
        
        size--;
        front++;
        if (front >= capacity) {
            front = 0;
        }
        
        return true;
    }
    
    int Front() {
        if (size == 0) {
            return -1;
        }
        return data[front];
    }
    
    int Rear() {
        if (size == 0) {
            return -1;
        }
        return data[rear];
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (size == capacity) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */