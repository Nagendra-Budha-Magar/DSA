#include<iostream>
using namespace std;

int Partion(int a[], int low, int high) {
    int pivot = a[low];
    int stateIndex = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (a[j] < pivot) {
            int temp = a[stateIndex];
            a[stateIndex] = a[j];
            a[j] = temp;
            stateIndex++;
        }
    }
    int swap = a[stateIndex - 1];
    a[stateIndex - 1] = a[low];
    a[low] = swap;

    return stateIndex - 1;
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = Partion(a, low, high);
        QuickSort(a,low,pivotIndex - 1);
        QuickSort(a,pivotIndex + 1,high);
    }
}

void printSort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    // int arr[] = {24,5,18,25,2,30};
    // int Size = sizeof(arr)/sizeof(arr[0]);

    int Size;
    cout << "Enter the size of Array" << endl;
    cin >> Size;

    int arr[Size];
    for (int i = 0; i< Size; i++) {
        cout << "Enter the value ";
        cin >> arr[i];
    }

    cout << "Original Array : ";
    printSort(arr,Size);

    QuickSort(arr,0,Size - 1);

    cout << "Sorted Array : ";
    printSort(arr,Size);
    return 0;
}