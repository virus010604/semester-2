#include <iostream>
using namespace std;

#define MAX_SIZE 9

class sistem {
public:
    int top;
    int data[MAX_SIZE];

    sistem() {
        top = -1;
    }

    bool isEmpty() {
    	return(top==-1);


    }

    bool isFull() {
    	return(top==MAX_SIZE-1) ;


    }

    void push(int value) {
    	if(isfull());
    	cout << "stack penuh : ";
    	return;
    	   top++;
    data(top)=value;
}


    }

    void pop() {

        if(isempty);
        cout << "tumpukan kosong : "endl;
        return;
          cout << "elemen yang dihapus << : "endl;


    }


    void display() {
    	//    	Isi Kode Disini

    void peek(){
    	//    	Isi Kode Disini
    }

    void bubbleSort(int arr[], int n) {
	if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }

	//    	Isi Kode Disini



	cout << "Data : ";
        for(int i = 0; i <= top; i++){
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    void selectionSort(int arr[], int n) {
    	if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }

	//    	Isi Kode Disini



	cout << "Data : ";
        for(int i = 0; i <= top; i++){
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    sistem s;
    int pilihan, angka_masuk, pilih_algo;
    bool keluar = false;
    while(!keluar) {
        cout << "=============================================================\n";
        cout << "          Selamat datang di sistem management angka\n";
        cout << "1. Push \n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Sort\n";
        cout << "6. Exit\n";
        cout << "=============================================================\n";
        cout << "Pilih menu dengan menginputkan angka berdasarkan list : ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                cout << "Masukkan angka : ";
                cin >> angka_masuk;
                s.push(angka_masuk);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "1. Bubble sort\n";
                cout << "2. Selection sort\n";
                cout << "Masukkan algoritma yang anda inginkan : ";
                cin >> pilih_algo;
                if (pilih_algo == 1){
                    s.bubbleSort(s.data, s.top + 1);
                } else if (pilih_algo == 2){
                    s.selectionSort(s.data, s.top + 1);
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
    cout << "Terimakasihhhhhhhhh :)\n";
    return 0;
}

