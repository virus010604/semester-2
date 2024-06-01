#include <iostream>

#define SIZE 9

using namespace std;

class Queue {
private:
    int data[SIZE];
    int data2[SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    void enqueue(int value, int value2) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        data[rear] = value;
        data2[rear] = value2;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue contents:\n";
        for (int i = front; i != rear; i = (i + 1) % SIZE) {
            cout << data[i] << "\t" << data2[i] << endl;
        }
        cout <<"data 1: "<< data[rear] << "\t data 2: " << data2[rear] << endl;
    }
};

int main() {
    Queue q;
    int opor;
    int opor2;
    char choice;

    do {
        cout << "Masukkan data1: "; cin >> opor;
        cout << "Masukkan data2: "; cin >> opor2;
        q.enqueue(opor, opor2);

        cout << "Ingin memasukkan data lagi? (y/n): "; cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    q.display();

    return 0;
}
