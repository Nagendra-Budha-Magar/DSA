// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
public:
    Node* next = nullptr;
    int data;
};

class StackSll{
public:
    Node* head = nullptr;

    void Push(int value) { //Pushing data from begining
        Node* n = new Node;
        n->data = value;
        if(head == nullptr){
            head = n;
        }else{
            n->next = head;
            head = n;
        }
    }

    void Pop(){
        if(head == nullptr) {
            cout<<"Stack is empty" << endl;
            return;
        }
        Node* First = head;
        head = head->next;
        delete First;
    }

    void Peek(){
        if(head == nullptr) {
            cout<<"Stack is empty" << endl;
            return;
        }
        cout << "Top element : " << head->data << endl; //Top mean head because head keep updating in top/begining while we push new data so Kei garna parena
    }

    void Print() {
        if(head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

};

int main() {
    StackSll Ssll;
    Ssll.Push(10);
    Ssll.Push(20);
    Ssll.Push(40);
    Ssll.Push(35);
    Ssll.Pop();
    Ssll.Peek();
    Ssll.Print();
    return 0;
}