#include <iostream>

using namespace std;


struct database
{
    string nama[3];
};

struct barang
{
    char pilihann;
    int pilihan;
    int stok[3] = {0,0,0};
    database item;
};

int main()
{
    barang a;
    cout << "selamat datang admin mermaidmidi" << endl;
    cout << "================================" << endl;
    cout << "data barang masih kosong silahkan masukan data" << endl;
    for(int z = 0;z < 3 ;z++){

    cout << "masukan nama barang "<<z+1<<": ";cin >> a.item.nama[z];
    }
    cout << "================================" << endl;
    cout << "data barang terbaru" << endl;
    ubahh:
     for(int b = 0;b < 3 ;b++){
    cout <<b+1<<".barang: "<< a.item.nama[b] <<"\nstok: "<<a.stok[b]<< endl;
     }

    cout << "masukan stok barang" << endl;
    cout << "pilih barang: "; cin >> a.pilihan;
    if(a.pilihan == 1){
    cout << "1.barang "<<a.item.nama[0]<<"\nstok: ("<<a.stok[0]<<") ubah :";cin >> a.stok[0];

    cout << "\n================================" << endl;
    cout << "1.barang :" << a.item.nama[0] <<"\njumlah stok: "<< a.stok[0];
    cout << "\n================================" << endl;
    }else if(a.pilihan == 2){
    cout << "2.barang "<<a.item.nama[1]<<"\nstok: ("<<a.stok[1]<<") ubah :";cin >> a.stok[1];

    cout << "\n================================" << endl;
    cout << "2.barang :" << a.item.nama[1] <<"\njumlah stok: "<< a.stok[1];
    cout << "\n================================" << endl;
    } else if(a.pilihan == 3){
    cout << "3.barang "<<a.item.nama[2]<<"\nstok: ("<<a.stok[2]<<") ubah :";cin >> a.stok[2];

    cout << "\n================================" << endl;
    cout << "3.barang :" << a.item.nama[2] <<"\njumlah stok: "<< a.stok[2] <<endl;
    cout << "\n================================" << endl;
    }else{
    cout <<"pilihan salah tidak ada di data" << endl;
    system("cls");
    }
        cout << "================data saat ini================" << endl;
        cout << "1.barang :" << a.item.nama[0] <<"\njumlah stok: "<< a.stok[0] << endl;
        cout << "2.barang :" << a.item.nama[1] <<"\njumlah stok: "<< a.stok[1] << endl;
        cout << "3.barang :" << a.item.nama[2] <<"\njumlah stok: "<< a.stok[2] << endl;
    cout << "\ningin mengubah data lagi (y/n): "; cin >> a.pilihann;
    if(a.pilihann == 'y' || a.pilihann == 'Y'){
        system("cls");
        goto ubahh;
    }else if(a.pilihann == 'n' || a.pilihann == 'N'){
        cout << "================terimaksih================" << endl;
    }else{
      cout <<"pilihan salah tidak ada di data" << endl;
    }

return 0;
}
