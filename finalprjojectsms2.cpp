#include <iostream>
#include <string>
#include <limits>

#define SIZE 10

using namespace std;

struct database
{
    int pilihan;
    float ukuran;
    char yn;
    int bonus[1] = {1000};
    int harga_normal[2] = {4500, 2500};
    int total;
    int total2;
    int jumlah;
    int bahasa;
    int donasikan;
    int perubahan;
    string userpass[2] = {"juan", "010604"};
    string z1;
    string z2;
    int ubah;
    string A;
};

// Deklarasi Queue untuk data botol
class Queue
{
private:
    database data[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }

    void enqueue(database value)
    {
        if (isFull())
        {
            cout << "fending machine full.\n";
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        data[rear] = value;
    }

    database dequeue()
    {
        database item = {0, 0, 0};
        if (isEmpty())
        {
            cout << "fending machine kosong\n";
            return item;
        }
        else if (front == rear)
        {
            item = data[front];
            front = rear = -1;
        }
        else
        {
            item = data[front];
            front = (front + 1) % SIZE;
        }
        return item;
    }

    database getFrontData()
    {
        if (isEmpty())
        {
            cout << "fending machine kosong.\n";
            return {0, 0, 0};
        }
        return data[front];
    }

    database getRearData()
    {
        if (isEmpty())
        {
            cout << "fending machine kosong.\n";
            return {0, 0, 0};
        }
        return data[rear];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "fending machine kosong.\n";
            return;
        }
        cout << "Daftar database:\n";
        cout << "Jumlah\tUkuran\tTotal\n";
        for (int i = front; i != rear; i = (i + 1) % SIZE)
        {
            cout << data[i].jumlah << "\t" << data[i].ukuran << "\t" << data[i].total2 << endl;
        }
        cout << data[rear].jumlah << "\t" << data[rear].ukuran << "\t" << data[rear].total2 << endl;
    }

    int getSize()
    {
        if (isEmpty())
        {
            return 0;
        }
        else if (front <= rear)
        {
            return rear - front + 1;
        }
        else
        {
            return SIZE - front + rear + 1;
        }
    }

    database *getData()
    {
        return data;
    }

    int getFront()
    {
        return front;
    }

    int getRear()
    {
        return rear;
    }
};

// Deklarasi global

// Fungsi

database a;
Queue botolQueue;

int akhir(struct database *);
int fungsi();
int ukuranml(struct database *);
int gelaskaca(struct database *);
int gelasplastik(struct database *);
int donasi(struct database *);
int ukuranml1(struct database *);
void admin(struct database *);
void bubbleSortQueue(Queue &q);
void displayMenu();

// Main
int main()
{
    admin(&a);
    return 0;
}

// Fungsi

void admin(struct database *a)
{
    cout << "\t\t\t\tWELCOME TO\n\t\t\t\tBottleMine" << endl;
    cout << "==============================================================================" << endl
         << endl;

    cout << "1.admin\n2.user" << endl;
    cout << "Anda akan masuk sebagai apa?: ";
    cin >> a->pilihan;
      if (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                system("cls");
                cout << "input salah!" << endl;
                admin (a);
                }
    if (a->pilihan == 1)
    {
        do
        {
            awal:
            cout << "masukan user: ";
            cin >> a->z1;
            cout << "Masukkan sandi: ";
            cin >> a->z2;
            if (a->z1 == a->userpass[0] && a->z2 == a->userpass[1])
            {   awal2:
                cout << "=================================================================" << endl;
                cout << "1.Harga Normal Botol Kaca(4500)\n2.Harga Normal Botol Plastik(2500)\n3.bonus awal(1000)\n4.ubah user atau pass\n5.kembali" << endl;
                cout << "apa yang anda ingin ubah? ";
                cin >> a->pilihan;
                if (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                system("cls");
                cout << "input salah!" << endl;
                goto awal2;
                }
                if (a->pilihan == 1)
                {
                    a->harga_normal[0];
                    cout << "masukan jumlah perubahan: ";
                    cin >> a->perubahan;
                    a->harga_normal[0] = a->perubahan;
                    system("cls");
                    cout << "perubahan telah di lakukan" << endl;
                    goto awal2;
                }
                else if (a->pilihan == 2)
                {
                    a->harga_normal[1];
                    cout << "masukan jumlah perubahan: ";
                    cin >> a->perubahan;
                    a->harga_normal[1] = a->perubahan;
                    system("cls");
                    cout << "perubahan telah di lakukan" << endl;
                    goto awal2;
                }
                else if (a->pilihan == 3)
                {
                    a->bonus[0];
                    cout << "masukan jumlah perubahan: ";
                    cin >> a->perubahan;
                    a->bonus[0] = a->perubahan;
                    system("cls");
                    cout << "perubahan telah di lakukan" << endl;
                    goto awal2;
                }
                else if (a->pilihan == 4)
                {
                    cout << "1.username\n2.password" << endl;
                    cout << "ingin merubah apa: ";
                    cin >> a->ubah;
                    if (a->ubah == 1)
                    {
                        cout << "masukan perubahan: ";
                        cin >> a->A;
                        a->userpass[0] = a->A;
                        system("cls");
                        cout << "perubahan telah di lakukan" << endl;
                        goto awal2;
                    }
                    else if (a->ubah == 2)
                    {
                        cout << "masukan perubahan: ";
                        cin >> a->A;
                        a->userpass[1] = a->A;
                        system("cls");
                        cout << "perubahan telah di lakukan" << endl;
                        goto awal2;
                    }
                    else
                    {
                        system("cls");
                        cout << "salah pilih!" << endl;
                        goto awal2;
                    }
                }
                else if (a->pilihan == 5)
                {
                    system("cls");
                    admin(a);
                }
            }else{
            system("cls");
            cout << "\npass atau user salah masukan lagi!" << endl;
            goto awal;
            }

        } while (a->z1 != a->userpass[0] && a->z2 != a->userpass[1]);
    }
    else if (a->pilihan == 2)
    {
        akhir(a);
    }else{
    cout << "pilihan salah silahkan masuk lagi!" << endl;
    cout << endl << endl;
    admin(a);
    }



    cout << "\n==============================================================================" << endl;
}

int fungsi()
{
    system("cls");
    cout << "======DISPLAY===================================================================\n\n"
         << "Ketentuan:\nBotol yang anda dapat masukkan:" << endl;
    cout << "1.Botol Kaca " << a.harga_normal[0] << "\n2.Botol Plastik " << a.harga_normal[1] << "\n3.kembali" << endl;
    cout << "Masukkan Pilihan anda(1/2): ";
    cin >> a.pilihan;
    cout << "\n==============================================================================" << endl;

    if (a.pilihan == 1)
    {
        gelaskaca(&a);
        r:
        cout << "apakah ingin menambah botol(y/n): ";
        cin >> a.yn;
        if (a.yn == 'y' || a.yn == 'Y')
        {
            cout << "data botol telah di simpan" << endl;
            return fungsi();
        }
        else if (a.yn == 'n' || a.yn == 'N')
        {
            cout << "data botol telah di simpan" << endl;
            return akhir(&a);
        }else{
        cout << "pilihan salah!" << endl;
        goto r;
        }
    }
    else if (a.pilihan == 2)
    {
        gelasplastik(&a);
        cout << "apakah ingin menambah botoly/n: ";
        cin >> a.yn;
        if (a.yn == 'y' || a.yn == 'Y')
        {
            return fungsi();
        }
        else if (a.yn == 'n' || a.yn == 'N')
        {
            return akhir(&a);
        }else{
        cout << "pilihan salah!" << endl;
        goto r;
        }
    }
    else if (a.pilihan == 3)
    {
        return akhir(&a);
    }
    else
    {
        cout << "Pilihan tidak terdapat di Display" << endl;
        return akhir(&a);
    }
}

int akhir(struct database *a)
{

        system("cls");
    bb:
        cout << "==============================================================================" << endl
             << endl;
        cout << "\t\t\t\tWELCOME TO\n\t\t\t\tBottleMine" << endl;
        cout << "==============================================================================" << endl
             << endl;
        cout << "Pilih opsi:\n1. Masukkan data botol\n2. Tampilkan antrian botol sebelum pengurutan\n3. Tampilkan antrian setelah pengurutan\n4. Tampilkan data botol pertama dan terakhir\n5. batalkan botol\n6. Keluar\n";
        cout << "Masukkan pilihan anda: ";
        cin >> a->pilihan;
          if (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                system("cls");
                cout << "input salah!" << endl;
                akhir(a);
                }
        if (a->pilihan == 1)
        {
            fungsi();
        }
        else if (a->pilihan == 2)
        {
            botolQueue.display();
            goto bb;
        }
        else if (a->pilihan == 3)
        {
            bubbleSortQueue(botolQueue);
            cout << "\nTampilan berdasar yang terkecil:\n";
            botolQueue.display();
            goto bb;
        }
        else if (a->pilihan == 4)
        {
            if (!botolQueue.isEmpty())
            {
                database firstBotol = botolQueue.getFrontData();
                database lastBotol = botolQueue.getRearData();
                cout << "\nData Botol Pertama:\n";
                cout << "Jumlah: " << firstBotol.jumlah << "\tUkuran: " << firstBotol.ukuran << "\tTotal2: " << firstBotol.total2 << endl;
                cout << "\nData Botol Terakhir:\n";
                cout << "Jumlah: " << lastBotol.jumlah << "\tUkuran: " << lastBotol.ukuran << "\tTotal2: " << lastBotol.total2 << endl;
                goto bb;
            }
            else
            {
                system("cls");
                cout << "antrian kosong.\n";
                goto bb;
            }
        }
        else if (a->pilihan == 5)
        {
            botolQueue.dequeue();
            botolQueue.display();
            goto bb;
        }
        else if (a->pilihan == 6)
        {
            if (!botolQueue.isEmpty())
            {
                cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "\nRedeem your last bill to cashier\n\nThank you Stay green:)\n"
                     << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
               return 0;
            }
            else
            {
                cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "\nThank you Stay green:)\n"
                     << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
                return 0;
            }
        }
        else
        {
            system("cls");
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
            goto bb;
        }
}

int gelaskaca(struct database *a)
{
    a->harga_normal[0];
    a->jumlah;
    cout << "ket: jika ukuran botol 350 ml harga normal.\n"
         << "     namun jika ukuran botol lebih dari 350 ml bertambah 1k." << endl;
    cout << "\n==============================================================================" << endl;
    w:
    cout << "Masukkan Jumlah botol: ";
    cin >> a->jumlah;
    cout << "Masukkan Ukuran Botol(ml): ";
    cin >> a->ukuran;
    while (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                cout << "input salah!" << endl;
                goto w;
                }
    ukuranml(a);
    return 0;
}

int ukuranml(struct database *a)
{

    if (a->ukuran > 350)
    {
        a->total2 = (a->jumlah * a->bonus[0]) + (a->harga_normal[0] * a->jumlah);
        cout << "bonus: " << a->bonus[0] << endl;
        cout << "uang yang di tukarkan: " << a->total2 << endl;

        donasi(a);
    }
    else if (a->ukuran > 0 && a->ukuran <= 350)
    {
        a->total2 = a->jumlah * a->harga_normal[0];
        cout << "uang yang di tukarkan: " << a->total2 << endl;

        donasi(a);
    }
    else
    {
        system("cls");
        cout << "ukuran yang anda masukkan salah!" << endl;
        gelasplastik(a);
    }

    botolQueue.enqueue(*a);

    return 0;
}

int ukuranml1(struct database *a)
{
    while (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                system("cls");
                cout << "input salah!" << endl;
                return gelasplastik(a);
    }

    if (a->ukuran > 350)
    {
        a->total2 = (a->jumlah * a->bonus[0]) + a->total;
        cout << "bonus: " << a->bonus[0] << endl;
        cout << "uang yang di tukarkan: " << a->total2 << endl;

        donasi(a);
    }
    else if (a->ukuran > 0 && a->ukuran <= 350)
    {
        a->total2 = a->total;
        cout << "uang yang di tukarkan: " << a->total2 << endl;

        donasi(a);
    }
    else
    {
        system("cls");
        cout << "ukuran yang anda masukkan salah!" << endl;
        gelasplastik(a);
    }

    botolQueue.enqueue(*a);


}

int gelasplastik(struct database *a)
{
    a->harga_normal[1];
    cout << "ket: jika botol tidak terdapat label Daur Ulang harga normal.\n"
         << "     namun jika botol terdapat label daur ulang bertambah 1k." << endl;
    cout << "ket: jika ukuran botol 350 ml harga normal.\n"
         << "     namun jika ukuran botol lebih dari 350 ml bertambah 1k." << endl;
    cout << "\n==============================================================================" << endl;
    cout << "masukan jumlah botol yang ingin ditukarkan: ";
    cin >> a->jumlah;
     while (cin.fail()) {
                cin.clear(); // Menghapus flag kesalahan
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input tidak valid
                system("cls");
                cout << "input salah!" << endl;
                return gelasplastik(a);
     }
    cout << "Apakah botol terdapat label daur ulang(y/n): ";
    cin >> a->yn;

    if (a->yn == 'y' || a->yn == 'Y')
    {
        a->total = (a->jumlah * a->harga_normal[1]) + (a->bonus[0] * a->jumlah);
        cout << "=============================================" << endl;
        cout << "bonus: " << a->bonus[0] << endl;
        cout << "masukkan ukuran botol(ml): ";
        cin >> a->ukuran;
        ukuranml1(a);
    }
    else if (a->yn == 'N' || a->yn == 'n')
    {
        a->total = a->jumlah * a->harga_normal[1];
        cout << "masukkan ukuran botol(ml): ";
        cin >> a->ukuran;
        ukuranml1(a);
    }
    else
    {
        cout << "pilihan yang anda masukkan salah" << endl;
        return gelasplastik(a);
    }

}

int donasi(struct database *a)
{
    // botol.total2 = a->total2;
    cout << "apakah anda ingin donasi ke kelompok pecinta alam(y/n): ";
    cin >> a->yn;
    if (a->yn == 'y' || a->yn == 'Y')
    {

        cout << "berapa yang anda ingin donasikan: ";
        cin >> a->donasikan;
        if (cin.fail())
        {
            cin.clear();
            cout << "Invalid input. Please enter a number: " << endl;
            return 0;
        }
        a->total2 = a->total2 - a->donasikan;
        if (a->donasikan > a->total2)
        {
            cout << "saldo tidak cukup" << endl;
            return donasi(a);
        }

        cout << "=======================struk======================" << endl;
        cout << "jumlah botol yang dimasukkan: " << a->jumlah
             << "\nukuran yang anda masukkan : " << a->ukuran << "ml"
             << "\nyang anda donasikan: " << a->donasikan
             << "\nuang yang ditukarkan: " << a->total2 << endl;
        cout << "==================================================" << endl;
    }
    else if (a->yn == 'n' || a->yn == 'N')
    {
        cout << "=======================struk======================" << endl;
        cout << "jumlah botol yang dimasukkan: " << a->jumlah
             << "\nukuran yang anda masukkan : " << a->ukuran << "ml"
             << "\nuang yang ditukarkan: " << a->total2 << endl;
        cout << "==================================================" << endl;
    }
    else
    {
        cout << "pilihan salah" << endl;
         return donasi(a);
    }
}

void bubbleSortQueue(Queue &q)
{
    int size = q.getSize();
    if (size <= 1)
        return;

    database *data = q.getData();
    int front = q.getFront();
    int rear = q.getRear();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = front; j != rear; j = (j + 1) % SIZE)
        {
            int next = (j + 1) % SIZE;
            if (data[j].total2 > data[next].total2)
            {
                database temp = data[j];
                data[j] = data[next];
                data[next] = temp;
            }
        }
    }
}
