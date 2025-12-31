#include<iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int searchValue) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (a[mid] == searchValue)
            return mid;
        if (a[mid] < searchValue) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return - 1;
}

int main() {
    int n;
    int key;

    cout << "Enter how many numbers you want to store in array" << endl;
    cin >> n;

    int* arr = new int[n]; // store data in heap
    for (int i = 0; i < n; i++) {
        cout << "Enter a numbers";
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << " " << arr[i] ;
    }
    cout << endl;

    cout << "Enter the number you want to search" << endl;;
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        cout << "The value is in index : " << result << endl;
    }else {
        cout << "The value is not there" << endl;
    }
    delete[] arr;   // Its required because we allocated memory dynamically in array
    return 0;
}