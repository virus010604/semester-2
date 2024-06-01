#include <iostream>
using namespace std;

#define MAX_SIZE 9

class sistem {
public:
    int* top;
    int* data= new int[MAX_SIZE];

    sistem() {
        top = new int;

        *top = -1;
    }
    ~sistem(){
    delete top;
    delete data;
    }


    bool isEmpty() {
        return (*top == -1);
    }

    bool isFull() {
        return (*top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh!" << endl;
            return;
        }
        (*top)++;
        data[*top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return;
        }
        cout << "Elemen terhapus: " << data[*top] << endl;
        (*top)--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }
        cout << "Isi stack: ";
        for (int i = 0; i <= *top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }
        cout << "Elemen paling atas: " << data[*top] << endl;
    }

    void bubbleSort(int arr[], int n) {
        int &r = n;

        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }

        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < r - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "Data setelah bubble sort: ";
        for (int i = 0; i < r; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void selectionSort(int arr[], int n) {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }

        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }

        cout << "Data setelah selection sort: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    sistem* s = new sistem;
    int pilihan, angka_masuk, pilih_algo;
    bool keluar = false;
    while (!keluar) {
        cout << "=============================================================\n";
        cout << "          Selamat datang di sistem manajemen angka\n";
        cout << "1. Push \n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Sort\n";
        cout << "6. Exit\n";
        cout << "=============================================================\n";
        cout << "Pilih menu dengan menginputkan angka berdasarkan list : ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
            cout << "Masukkan angka : ";
            cin >> angka_masuk;
            s->push(angka_masuk);
            break;
        case 2:
            s->pop();
            break;
        case 3:
            s->peek();
            break;
        case 4:
            s->display();
            break;
        case 5:
            cout << "1. Bubble sort\n";
            cout << "2. Selection sort\n";
            cout << "Masukkan algoritma yang anda inginkan : ";
            cin >> pilih_algo;
            if (pilih_algo == 1) {
                s->bubbleSort(s->data, *s->top + 1);
            } else if (pilih_algo == 2) {
                s->selectionSort(s->data, *s->top + 1);
            } else {
                cout << "Pilihan algoritma tidak valid!\n";
            }
            break;
        case 6:
            keluar = true;
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
    cout << "Terima kasih :)\n";
    return 0;

    delete s;
}
