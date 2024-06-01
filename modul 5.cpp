//Juan P Kuganda_f55123061
#include <iostream>
#define MAX_SIZE 100
using namespace std;
class Stack{
private:
    int top;
    int data[MAX_SIZE];
public:
    Stack(){
    top = -1;
    }
    bool isEmpty(){
    return top == -1;
    }
    bool isFull(){
    return top == MAX_SIZE - 1;
    }
    void push(int value){
    if (isFull()){
        cout << "Stack overflow!" << endl;
        return;
        }
        data[++top] = value;
    }
    void pop(){
    if (isEmpty()){
        cout << "Stack overflow!" << endl;
        return;
        }
        top--;
    }
    void display(){
        if (isEmpty()){
        cout << "Stack is Empty" << endl;
        return;
        }
    cout << "data : ";
    for(int i = 0; i <= top; i++){
        cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main(){
Stack stack;
stack.push(10);
stack.push(20);
stack.push(30);
stack.display();
stack.pop();
stack.display();
}
