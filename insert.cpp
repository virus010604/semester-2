#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "dapartemen " << i + 1 << " : " << arr[i] << endl;
    }
    cout << endl;
}
int main()
{

    int arr[5];
    cout << "data kariyawan masing-masing dapartemen\ndari yang memiliki kariyawan sedikit  hingga yang paling banyak\n"
         << endl;
    cout << "=======================\n";
    for (int z = 0; z < 5; z++)
    {
        cout << "masukan data kariyawan masing masing dapartemen\n"
             << "dapartemen " << z + 1 << " : ";
        cin >> arr[z];
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\n=======================\n";
    cout << "data mentah: " << endl;
    printArray(arr, n);

    // setelah proses insert
    insertionSort(arr, n);
    cout << "data telah di urutkan: " << endl;
    printArray(arr, n);

    return 0;
}