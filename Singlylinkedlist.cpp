#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        do {
            if (temp->data == targetValue) {
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == tail) {
                    tail = newNode;
                }
                tail->next = head;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }

    void insertBefore(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == targetValue) {
                if (prev == nullptr) {
                    newNode->next = head;
                    head = newNode;
                    tail->next = head;
                } else {
                    prev->next = newNode;
                    newNode->next = temp;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked List kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }

    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
     void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == value) {
                if (prev == nullptr) {
                    if (head == tail) {
                        delete head;
                        head = nullptr;
                        tail = nullptr;
                        return;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete temp;
                        return;
                    }
                } else {
                    prev->next = temp->next;
                    if (temp == tail) {
                        tail = prev;
                    }
                    delete temp;
                    tail->next = head;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
    }

    void deleteAfter(int targetValue) {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == targetValue) {
                Node* nodeToDelete = temp->next;
                if (nodeToDelete == head) {
                    cout << "Tidak ada node setelah node dengan nilai " << targetValue << "." << endl;
                    return;
                }
                temp->next = nodeToDelete->next;
                if (nodeToDelete == tail) {
                    tail = temp;
                }
                delete nodeToDelete;
                tail->next = head;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }

    void deleteBefore(int targetValue) {
        if (head == nullptr || head->next == nullptr || head->data == targetValue) {
            cout << "Tidak ada node sebelum node dengan nilai " << targetValue << "." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        Node* prevPrev = nullptr;
        do {
            if (temp->next != nullptr && temp->next->data == targetValue) {
                if (prev == nullptr) {
                    Node* nodeToDelete = head;
                    head = head->next;
                    tail->next = head;
                    delete nodeToDelete;
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                tail->next = head;
                return;
            }
            prevPrev = prev;
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(1);
    list.insertAfter(1,30);
    list.insertAtEnd(2);
    list.insertAtBeginning(9);
    list.insertAtBeginning(10);
    list.deleteBefore(1);
    list.deleteAfter(10);
    //list.deleteNode(30);
    //list.deleteAtEnd();
    list.display();

    return 0;
}
