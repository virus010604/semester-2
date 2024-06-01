//Juan P Kuganda_F55123061
#include <iostream>
using namespace std;
/*
struct dosen {
string nama[5] = {"rahma","yasdi","nouval","ryfial","adhiguna"};
};

struct mahasiswa {
    string nama;
    dosen dosenwali;
};

int main(){
    mahasiswa mhs1;
    mhs1.nama = "Juan";

    cout << "nama: " << mhs1.nama << endl;
    cout << "dosen wali: " << mhs1.dosenwali.nama[4] << endl;
    return 0;
}
*/
struct test{
int b;
};
int main(){
test t;
int p;
int z = 100;
int *a = nullptr;
a = &z;
z = p;
int r = 90;
int &s = r;
cout << "nilai alamat a: " << *a << endl;
cout << "nilai alamat a: " << a << endl;
cout << "nilai alamat p: " << p << endl;
cout << "nilai alamat p: " << &p << endl;
cout << "nilai alamat b: " << t.b << endl;
cout << &r << endl;
cout << "nilai alamat r: " << &s << endl;
cout << "nilai alamat r: " << s << endl;
}
