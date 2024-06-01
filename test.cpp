#include <iostream>
#include <string>

 using namespace std;

 int main(){
 int top = 0;
 int maksimal = 5;
 int arraydata[5];
 int data;

 cout << "data array stack:\n" << endl;

   for (int i = top; i < maksimal; i++) {
    cout << "Masukkan data ke-" << i + 1 << ": ";
    cin >> arraydata[i];
  }

  // Tampilkan data
  if(arraydata[top] = maksimal){
    cout << "data penuh" << endl;
  }else{
  cout << endl << "Data array:" << endl;
  for (int i = top; i < maksimal; i++) {
    cout << "Data ke-" << i + 1 << ": " << arraydata[i] << endl;
  }
  }


cout << "\n" << endl;
cout << "ini data ke-4: " << arraydata[3] << endl;



 return 0;
 }
