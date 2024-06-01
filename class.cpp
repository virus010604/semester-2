//Juan P Kuganda_F55123061
#include <iostream>

using namespace std;

class Persegi{
protected:
    int panjangSisi;
    int luas()
    {
        return panjangSisi * panjangSisi;
    }
    int Keliling()
    {
        return 4 * panjangSisi;
    }
    TampilkanPersegi(){
        cout << "luas persegi: " << luas() << "Keliling" << Keliling();
    }
};

class Kubus: public Persegi{
public:
    Kubus(int K){
    panjangSisi = K;
    }
    int Volume(){
    return panjangSisi * panjangSisi * panjangSisi;
    }
    int luasPermukaan(){
    return 6 * luas();
    }
    void Tampilkan(){
    cout << "Luas Permukaan Persegi:" << luasPermukaan() << ", Volume: " << Volume() << "\n\n";
    TampilkanPersegi();
    }
} ;

int main(){
Kubus K(10);
K.Tampilkan();
}
