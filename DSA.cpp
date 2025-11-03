#include<iostream>
using namespace std;

class Stack {
public:
    int top = 0;
    int arr[3];

    int isFull() {
        return top == sizeof(arr)/sizeof(arr[0]);
    }

    void push(int data) {
        if (isFull()) {
            cout<<"Stack is full" << endl;
        }
        arr[top] = data;
        top += 1;
    }
    void pop() {
        if (top == 0) {
            cout<< "Stack is empty"<< endl;
        }
        top -= 1;
    }

    void print() {
        for (int i = 0; i < top; i++) {
            cout<< arr[i] << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();

    s.print();

    return 0;
}