/*
 *	Author: liyunghao<liyunghao@gmail.com>
 *	Problem Link: https://leetcode.com/problems/design-circular-queue/
 *	Runtime: 51ms
 *	language: C++
*/
class MyCircularQueue {
public:
    int sz, front, rear;
    int occupied;
    vector<int> q;
    MyCircularQueue(int k) {
        q.resize(k);
        front = 0;
        rear = -1;
        sz = k;
        occupied = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        rear = (rear + 1) % sz;
        q[rear] = value;
        ++occupied;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        front = (front+1) % sz;
        --occupied;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    
    bool isEmpty() {
        return occupied == 0;
    }
    
    bool isFull() {
        return occupied == sz;
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
