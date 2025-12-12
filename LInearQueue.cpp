#include<iostream>
using namespace std;

class Queue {
public:
    int front = 0;
    int rear = 0;
    int a[4];

    bool isFull(){
        return rear == sizeof(a)/sizeof(a[0]);
    }

    void EnQueue(int data) {
        if(isFull()){
            cout<<"rear is full"<<endl;
            return;
        }
        a[rear] = data;
        rear += 1;
    }

    bool isEmpty(){
        return front == rear;
    }


    int DeQueue(){
        if(isEmpty()){
            cout<<"front is empty"<< endl;
            return false;
        }
        int prev = a[front];
        front += 1;
        return -1;
    }

    void print(){
        for(int i = front; i< rear; i++){
            cout<<a[i]<< endl;
        }
    }
};

int main(){
    Queue Q;
    Q.EnQueue(10);
    Q.EnQueue(15);
    Q.EnQueue(20);
    Q.EnQueue(25);
    Q.EnQueue(30);
    Q.DeQueue();
    Q.print();


    return 0;
}
