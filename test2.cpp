#include <iostream>
using namespace std;

int main() {
    int tinggi;

    cout << "Masukkan tinggi ketupat: ";
    cin >> tinggi;

    for (int i = 0; i <= tinggi; i++) {
        for (int j = 1; j <= tinggi - i; j++)
            cout << " ";

        for (int k = 0; k <= 2 * i; k++)
            cout << "*";

        cout << endl;
    }

    for (int i = tinggi - 1; i >= 0; i--) {
        for (int j = 1; j <= tinggi - i; j++)
            cout << " ";

        for (int k = 0; k <= 2 * i; k++)
            cout << "*";

        cout << endl;
    }

    return 0;
}
