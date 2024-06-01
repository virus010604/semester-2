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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAfter(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        Node* temp = head;
        do {
            if (temp->data == targetValue) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }

    void insertBefore(int targetValue, int newValue) {
        Node* newNode = new Node(newValue);
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            delete newNode;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;

        do {
            if (temp->data == targetValue) {
                if (prev == nullptr) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    newNode->next = head;
                    last->next = newNode;
                    head = newNode;
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
        delete newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked List: NULL" << endl;
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

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == value) {
                if (prev == nullptr) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    if (head == head->next) {
                        delete head;
                        head = nullptr;
                    } else {
                        last->next = head->next;
                        delete head;
                        head = last->next;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
    }

    void deleteAfter(int targetValue) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == targetValue) {
                if (temp->next == head) {
                    cout << "Tidak ada node setelah node dengan nilai " << targetValue << "." << endl;
                    return;
                }
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node dengan nilai " << targetValue << " tidak ditemukan." << endl;
    }

    void deleteBefore(int targetValue) {
        if (head == nullptr || head->next == head) {
            cout << "Tidak ada node sebelum node dengan nilai " << targetValue << "." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        Node* prevPrev = nullptr;

        do {
            if (temp->next->data == targetValue) {
                if (prev == nullptr) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    if (head == head->next) {
                        delete head;
                        head = nullptr;
                    } else {
                        last->next = head->next;
                        delete head;
                        head = last->next;
                    }
                } else if (prevPrev == nullptr) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    last->next = head->next;
                    delete head;
                    head = last->next;
                } else {
                    prevPrev->next = temp;
                    delete prev;
                }
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
    CircularLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();
    list.deleteNode(1);
    list.display();
    list.insertAtBeginning(1);
    list.display();
    list.deleteAfter(1);
    list.display();
    list.insertAfter(1, 2);
    list.insertAfter(2, 3);
    list.display();
    list.deleteBefore(3);
    list.display();
    return 0;
}
