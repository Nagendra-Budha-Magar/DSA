#include<iostream>
using namespace std;

class Node {
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    int data;
};

class DoublyLL {
public:
    Node* head = nullptr;
    void insertAtBegining(int value) {
        Node* n = new Node();
        n->data = value;
        if (head == nullptr) {
            head = n;
            return;
        }
        head->prev = n;
        n->next = head;
        head = n;    // It make sure that head is pointing to new node we make
    }

    void deleteAtBegining() {
        if (head == nullptr) {
            cout << "LinkedList is Empty" << endl;
            return;
        }
        Node* first = head;
        head = head->next;
        head->prev = nullptr;
        delete first;
    }


    void insertAtEnd(int value) {
        Node* n = new Node();
        n->data = value;
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* temp = head;      // Making "temporary pointer variable" of node for traverse through Nodes
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "Linked list is Empty" << endl;
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

    void insertAtPosition(int pos, int value) {     // pos means position hai
        Node* n = new Node();
        n->data = value;
        if (pos == 0) {
            insertAtBegining(value);
            return;
        }
        Node* temp = head;
        int count = 0;
        // It goes till the node when temp is 1 node less than the node of position we want to insert
        while (count < (pos - 1) && temp != nullptr) {  // May be, Better use for loop
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Out of Range" << endl;
            return;
        }

        n->next = temp->next;
        n->prev = temp;

        if(temp->next != nullptr) {
            temp->next->prev = n;
        }
        temp->next = n;
    }

    void deleteAtPostion(int pos) {     // Here pos mean position/index of node that i want to delete
        if (head == nullptr) {
            cout << "Linked List is Empty" << endl;
            return;
        }
        if (pos == 0) {
            deleteAtBegining();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < (pos -1); i++) {
            temp = temp->next;
        }
        Node* Curr = temp->next;        // Curr is the position of n0de we want to delete
        if (Curr == nullptr) {
            cout << "Out of Range" << endl;
            return;
        }
        temp->next = Curr->next;
        if (Curr->next != nullptr) {
            Curr->next->prev = temp;
        }
        delete Curr;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLL Dll;
    Dll.insertAtBegining(5);
    Dll.insertAtBegining(10);
    Dll.insertAtBegining(15);
    Dll.insertAtEnd(20);
    Dll.deleteAtBegining();
    Dll.deleteAtEnd();
    Dll.insertAtPosition(1,25);
    Dll.insertAtPosition(2,30);
    Dll.deleteAtPostion(2);
    Dll.print();

    return 0;
}