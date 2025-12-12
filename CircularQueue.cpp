#include<iostream>
using namespace std;

class CirQueue {
public:
    int size = 5;
    int a[5];
    int front = 0;
    int rear = 0;

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    bool isEmpty() {
        return(rear == front);
    }

    void EnQueue(int data) {
        if (isFull()){
            cout << "Queue is Full" << endl;
            return;
        }
        a[rear] = data;
        rear = (rear + 1) % size;
    }

    int DeQueue (){
        if (isEmpty()) {
            cout<< "Queue is Empty" << endl;
            return -1;
        }
        int prev = a[front];
        front = (front + 1) % size;
        return prev;
    }

    void Print(){
        if(isEmpty()){
            cout<< "Queue is Empty" << endl;
            return;
        }
        int i = front;
        while(i != rear) {
            cout << a[i] << endl;
            i = (i + 1) % size;
        }

    }
};

int main(){
    CirQueue CQ;
    CQ.EnQueue(10);
    CQ.EnQueue(11);
    CQ.EnQueue(12);
    CQ.EnQueue(13);
    CQ.EnQueue(14);

    CQ.DeQueue();
    // CQ.DeQueue();
    // CQ.DeQueue();
    // CQ.DeQueue();

    CQ.Print();

    return 0;
}
