#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAfter(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }

        if (temp == tail) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    void insertBefore(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
            return;
        }

        if (temp == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;
        }
    }

    void displayForward() {
        Node* temp = head;
        cout << "Doubly Linked List (forward) : ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void displayBackward() {
        Node* temp = tail;
        cout << "Doubly Linked List (backward) : ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
            return;
        }

        if (temp == head && temp == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (temp == head) {
            head = temp->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = temp->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    list.displayForward();

    list.displayBackward();

    list.insertBefore(2, 5);

    list.displayForward();

    list.insertAfter(5, 7);

    list.displayForward();

    return 0;
}
