#include <iostream>
using namespace std;
// stack deklarasi
int maksimal = 5;
int top = 0;
string arraybuku[5];

// antrian deklarasi
int maksimalantrianarray = 5, depan = 0, belakang = 0;
string antrianaa[5];

void pusharray(string data);
void displayarray();

int pull();
bool apakahfull();
int anaa(string data);
bool kosong();
void view();
string input1;
string input2;
char choice;

int main()
{
    cout << "DATA STACK DAN QUEUE\n"
         << endl;
    cout << "A.STACK\nB.QUEUE\nMasukan Pilihan Jeni Data: ";
    cin >> choice;
    if (choice == 'A'|| choice == 'a')
    {
    cout<< "=============" << endl;
    awal:
    system("cls");
    displayarray();
    for (int i = top; i < maksimal; i++)
    {
        cout <<i+1<< ".masukan data: ";cin>> input1;
        pusharray(input1);
        goto awal;
    }
    cout<< "=============" << endl;
        return 0;
    }
    else if (choice == 'B'|| choice == 'b')
    {
    cout<< "=============" << endl;
    awal1:
    system("cls");
    view();
    for (int i = top; i < maksimal; i++)
    {
        cout <<i+1<< ".masukan data: ";cin>> input2;
        anaa(input2);
        goto awal1;
    }
    cout<< "=============" << endl;
    return 0;
    }
    else
    {
        cout << "input salah!" << endl;
    }

    return 0;
}
int pull(){
cout << "full!" << endl;
return 0;
}
// stack

void pusharray(string data)
{
    if (top >= maksimal)
    {
        cout << "data penuh" << endl;
    }
    else
    {
        arraybuku[top] = data;
        top++;
    }
}
void displayarray()
{
    cout << "Data stack array: " << endl;
    for (int i = maksimal-1; i >= 0; i--)
    {
        if (arraybuku[i] != "")
        {
            cout << i + 1 << ".Data: " << arraybuku[i] << endl;
        }
        else
        {
            cout << "kosong!" << endl;
        }
    }
    cout << "\n"
         << endl;
}

// queue
bool apakahfull()
{
    if (belakang == maksimalantrianarray)
    {

        return true;
    }
    else
    {
        return false;
    }
}

bool kosong()
{
    if (belakang == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int anaa(string data)
{

    if (apakahfull())
    {
        pull();
    }
    else
    {
        if (kosong())
        {
            antrianaa[0] = data;
            depan++;
            belakang++;
        }
        else
        {
            antrianaa[belakang] = data;
            belakang++;
        }
    }
    return 0;
}

void view()
{
    cout << "data antrian: " << endl;
    if (kosong())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < maksimalantrianarray; i++)
        {
            if (antrianaa[i] != "")
            {
                cout << i + 1 << ". " << antrianaa[i] << endl;
            }
            else
            {
                cout << i + 1 << ".kosong " << endl;
            }
        }
    }
}
