#include <iostream>
using namespace std;

#define maxx 4

class proses
{
private:
    struct awal
    {
        int arr[maxx];
        int temp;
        int top;
        awal(){
            top = -1;
        }
    };

public:
    struct stack
    {
        awal inisiasi;
        bool isempty(){
            return inisiasi.top <= -1;
        }
        bool isfull(){
            return inisiasi.top == maxx-1;
        }
        void push(int value){
            if(isfull()){
                cout << "Stack Overflow" << endl;
            }else {
                inisiasi.arr[++inisiasi.top] = value;}
        }
        void pop(){
            if (isempty())
            {
                cout << "Stack Underflow" << endl;
                return;
            }
            inisiasi.top--;
        }
        void display(){
            if(isempty()){
                cout << "Stack Kosong" << endl;
            }
            for (int i = 0; i <= inisiasi.top; i++){
                cout << inisiasi.arr[i] << " " ;
            }
            cout << endl;
            if(isfull()){
                cout << "Stack Full" << endl;
            }
        }

    };
    struct sorting
    {
        awal awal;
        void bubble(int arr[], int n){
            for (int i = 0; i < n - 1 ; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }

        void insert(int arr[], int n){
            for (int i = 1; i < n; i++)
            {
                for (int j = i; j > 0; j--){
                    if (arr[j] < arr[j-1]){
                        awal.temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = awal.temp;
                    }else {
                        break;
                    }
                }
            }
        }
        void selec(int arr[], int n){
            int min;
            for (int i = 0 ; i < n ; i++){
                min = i;
                for(int j = i+1; j < n ; j++){
                    if (arr[j] < arr[min]){
                        min = j;
                    }
                }
                awal.temp = arr[i];
                arr[i] = arr[min];
                arr[min] = awal.temp;
            }
        }

    };

};

int main(){
    proses::stack stack;
    proses::sorting sorting;
    int nilai;
    int plh;
    int pl;

        ulang :
        lagi:
        system("cls");
        stack.display();
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Sort" << endl;
        cout << "Pilihan Anda : ";
        cin >> plh;

        switch (plh)
        {
        case 1:
            cout << "Masukan Nilai Yang ingin anda tambahkan : ";
            cin >> nilai;
            stack.push(nilai);
            goto ulang;;
        case 2:
            stack.pop();
            goto ulang;
        case 3:
             cout << "1.buble sort" << endl;
             cout << "2.insertion sort" << endl;
             cout << "3.Selection Sort" << endl;
             cout << "Pilihan Anda : ";
             cin >> pl;
             switch (pl)
             {
             case 1:
                sorting.bubble(stack.inisiasi.arr, stack.inisiasi.top + 1 );
                goto ulang;
             case 2:
                sorting.insert(stack.inisiasi.arr, stack.inisiasi.top + 1);
                goto ulang;
            case 3:
                sorting.selec(stack.inisiasi.arr, stack.inisiasi.top + 1);
                goto ulang;
             default:
                break;
             }
            break;
        default:
            cout << "Pilihan anda salah" << endl;
            break;
        }
}
