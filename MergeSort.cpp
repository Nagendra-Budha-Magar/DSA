#include<iostream>
using namespace std;

void merge(int a[], int start, int mid, int end) {
    int size1 = (mid - start) + 1;
    int size2 =  end - mid;

    int leftArray[size1];
    int rightArray[size2];

    int i = 0;
    for (; i < size1; i++) {
        leftArray[i] = a[start + i];
    }
    int j = 0;
    for (; j < size2; j++) {
        rightArray[j] = a[mid + 1 + j];
    }
    //Reseting the value
    i = 0;
    j = 0;
    // k for main array
    int k = start;

    //Real Work start from here
    while (i < size1 && j < size2) {
        if (leftArray[i] < rightArray[j]) {
            a[k] = leftArray[i];
            i++;
        }else {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Ensuring if missed any
    while (i < size1) {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < size2) {
        a[k] = rightArray[j];
        j++;
        k++;
    }

}

void mergeSort( int a[], int start, int end) {
    if (start>=end)
    return;
    int mid = start + (end - start) / 2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a, start, mid ,end);
}

void printSort(int a[], int size) {
    cout << "Sorted Array ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

int main() {

    // int arr[]= {2,4,8,6,5,7,1,3};
    // int n = sizeof(arr)/sizeof(arr[0]);

    int n;  // Size of array
    cout << "Enter the size of Array you want to store" << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the value ";
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    printSort(arr,n);

    return 0;
}