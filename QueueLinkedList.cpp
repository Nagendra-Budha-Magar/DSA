#include<iostream>
using namespace std;

class Node {
public:
    Node* next = nullptr;
    int data;
};

class QueueSLL {
    Node* rear = nullptr;
    Node* front = nullptr;
public:
    void EnQueue(int value) {
        Node* n = new Node();
        n->data = value;
        if (rear == nullptr) {
            rear = front = n;
        }else {
            rear->next = n;
            rear = n;
        }
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        // prevent from rear to point in previous node
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() {
        // If condition checks if front is null or not to prevent from crash
        if (front != nullptr) {
            cout << "Peek value is " << front->data << endl;
        }
    }

    void print() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    QueueSLL Qsll;
    Qsll.EnQueue(5);
    Qsll.EnQueue(10);
    Qsll.EnQueue(15);
    Qsll.EnQueue(20);
    Qsll.Dequeue();
    Qsll.Dequeue();
    Qsll.peek();
    Qsll.print();

    return 0;
}