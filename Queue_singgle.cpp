#include <iostream>

#define SIZE 9

using namespace std;

class Queue {
private:
    int data[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        data[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Data : ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(0);
    q.enqueue(0);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(6);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
//    q.enqueue(2);
    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
