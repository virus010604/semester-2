// Andi Muhammad Fayyadh_F55123094
#include <iostream>
#include <conio.h>
#define maxstack 5
using namespace std;
void habisin();
struct STACK{
    private:
      int top;
      string data[5];
    public:
bool isfull()
{
      if(top == maxstack)
            return true;
      else
            return false;
}
bool isempty()
{
      if(top == -1)
            return true;
      else
            return false;
}
void push(string dta)
{
     if(isfull() == true)
      {
            cout << ("Maaf, RAK penuh");
      }
      else{
            habisin();
            top++;
            data[top]=dta;
      }
}
void pop()
{
      if(isempty() == true)
      {
            cout<<"BUKU telah kosong!";
      }
      else
      {
            cout<<"BUKU yang terambil : " <<data[top]<<endl;
            top--;
      }
}


void print()
{
      cout <<("\nData yang terdapat dalam RAK BUKU : \n");
      cout <<("--------------------------------\n");
      for(int i=0; i<=top-1; i++)
      {

            cout<<i+1<<"."<<data[i+1]<< endl;
      }
}

void clear()
{
      top = -1;
      cout<<("\nSekarang RAK kosong");
}\
};

struct database{

public:
string dta;
struct STACK stackbaru;
};
database z;

void habisin(){
 system("cls");
}

int main()
{

      //pendeklarasian variabel
      char menu;
      char ulang;
      //perulangan dengan do-while
      do
      {
            cout <<("\t PERPUSTAKAN MERMAID\n");
            cout <<("\t===============\n");
            cout <<("Menu : ") << endl;
            cout <<("\n1. AMBIL BUKU") << endl;
            cout <<("2. MASUKAN BUKU") << endl;
            cout <<("3. TOTAL DI MASUKAN") << endl;
            cout <<("4. KELUARKAN SEMUA BUKU") << endl;
            cout <<("5. KELUAR PERPUS") << endl;
            cout <<("6CUMAN TES YAH") << endl;

            cout<<"Menu pilihan Anda : ";
            cin>>menu;



            if(menu == '1')
            {
                  z.stackbaru.pop();
                  ulang = 'y';
                  getch();
                  habisin();
            }
            else if(menu == '2')
            {
                  cout<<"\nTambah BUKU";
                  cout<<"\n-----------";
                  cout<<"\nBUKU yang akan disimpan di RAK BUKU : ";
                  cin>>z.dta;
                  z.stackbaru.push(z.dta);
                  ulang = 'y';



            }
            else if(menu == '3')
            {
                  z.stackbaru.print();
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
                  habisin();
            }
            else if(menu == '4')
            {
                  z.stackbaru.clear();
                  cout<<"\n\nUlang ? (y/t)";
                  cin>>ulang;
                  habisin();
            }
            else if(menu == '5')
            {
                else if(menu == '6')
                {

                  exit(0);
            }else{
                cout << "PILIHAN TIDAK TERDAPAT DALAM MENU!" << endl;
                cout<<"\n\nUlang ? (y/t)";
                cin>>ulang;
            }
       }while(ulang == 'Y' || ulang == 'y');
}
