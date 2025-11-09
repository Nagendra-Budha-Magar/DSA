#include<iostream>
using namespace std;

class Stack {
public:
    int top = 0;
    int arr[3];

    //To watch is the array/stack is full or not
    int isFull() {
        return top == sizeof(arr)/sizeof(arr[0]);
    }

    //To add the data in stack from last as top goes up as increasing
    void push(int data) {
        if (isFull()) {
            cout<<"Stack is full" << endl;
            return;
        }
        arr[top] = data;
        top += 1;
    }

    //To remove the data from stack
    void pop() {
        if (top == 0) {
            cout<< "Stack is empty"<< endl;
            return;
        }
        top -= 1;
    }

    // To print the top element/data of stack.
    void peek() {
        if (top == 0) {
            cout<<"Stack is empty"<< endl;
            return;
        }
        cout<<"top element :"<< arr[top - 1]<< endl;
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
    s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    s.print();
    s.peek();

    return 0;
}