#include<iostream>
using namespace std;

class Node {
public:
    Node* next = nullptr;
    int data;
};

class SinglyLL {
public:
    Node* head = nullptr;

    void insertAtBegining( int value) {
        Node* n = new Node();
        n->data = value;
        if (head == nullptr) {
            head = n;
        }else {
            n->next = head;
            head = n;
        }
    }

    void deleteAtBegining() {
        if (head == nullptr) {
            cout<<"LinkedList is Empty"<<endl;
            return;
        }
        Node* first = head;
        head = head->next;
        delete first;
    }

    void insertAtEnd(int value) {
        Node* n = new Node();
        n->data = value;

        if (head==nullptr) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout<<"LinkedList is Empty"<<endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* Slast = head;
        while (Slast->next->next != nullptr) {
            Slast = Slast->next;
        }
        Node* last = Slast->next;
        Slast->next = nullptr;
        delete last;
    }

    void InsertAtNPosition( int value, int position) {
        if (position == 0) {
            insertAtBegining(value);
            return;
        }

        Node* n = new Node();
        n->data = value;
        Node* prev = head;
        int Current_pos = 0;
        while (Current_pos < (position - 1)) {
            prev = prev->next;
            Current_pos++;
        }
        n->next = prev->next;
        prev->next = n;
    }

    void deleteAtPosition(int position) {
        if (position == 0) {
            deleteAtBegining();
            return;
        }
        Node* prev = head;
        int count = 0;
        while (count < (position-1)) {
            prev = prev->next;
            if (prev == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            count++;
        }
        Node* curr = prev->next;
        prev-> next = curr->next;
        delete curr;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data<< endl;
            temp = temp->next;
        }
    }
};

int main() {
    SinglyLL sll;
    sll.insertAtBegining(3);
    sll.insertAtBegining(4);
    sll.insertAtBegining(5);
    sll.insertAtEnd(15);
    sll.insertAtEnd(20);
    sll.deleteAtBegining();
    sll.deleteAtEnd();
    sll.InsertAtNPosition(6,2);
    sll.deleteAtPosition(1);
    sll.print();
    return 0;
}