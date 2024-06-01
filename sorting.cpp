//Juan P Kuganda_F55123061
#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i = 0 ; i < (n-1) ; i++){
        for(int j = 0; j < (n-1); j++){
            if(arr[j] > arr [j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionsort(int arr[], int n){
    for(int i = 1;i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr [j] = arr[j-1];
                arr[j-1] = temp;
            }else{
                break;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_Idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_Idx]) {
        min_Idx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_Idx];
    arr[min_Idx] = temp;
  }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
	}
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
	}
    i = 0;
    j = 0;
    k = l;
    for (k = l; i < n1 && j < n2; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
    for (; i < n1; i++, k++){
        arr[k] = L[i];
    }
    for (; j < n2; j++, k++){
        arr[k] = R[j];
	}
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
	}
}
int main(){
	int arr[] = {7,3,5,7,8,9,1,2,5,10};
	int lenarr = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,lenarr);
	cout << "bubble sort \n";
	for(int i = 0; i < lenarr;i++){
        cout << arr[i] << " ";
	}
	cout << endl;
    int arrb[] = {62,21,4,36,77,8,1,24,4,9};
	int lenarrb = sizeof(arrb)/sizeof(arrb[0]);
	insertionsort(arrb,lenarrb);
	cout << "insert sort \n";
	for(int i = 0; i < lenarrb;i++){
        cout << arrb[i] << " ";
	}
	cout << endl;

    int arrc[] = {16,13,14,12,17,18,11,15,19,20};
	int lenarrc = sizeof(arrc)/sizeof(arrc[0]);
    selectionSort(arrc,lenarrc);
	cout << "selection sort \n";
	for(int i = 0; i < lenarrc;i++){
        cout << arrc[i] << " ";
	}
	cout << endl;

    int arrd[] = {161,132,140,120,170,18,11,151,19,210};
	int lenarrd = sizeof(arrd)/sizeof(arrd[0]);
	mergesort(arrd, 0, lenarrd-1 );
	cout << "merge sort \n";
	for(int i = 0; i<lenarrd; i++){
		cout << arrd[i] << " ";
	}
	cout << "\n";

	return 0;
}
