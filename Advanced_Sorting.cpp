#include <iostream>
using namespace std;

// For MergeSort Algorithm
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
// This is recursive part of MergeSort
void mergeSort( int a[], int start, int end) {
    if (start>=end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a, start, mid ,end);
}
// Printing Merge Sort
void printMergeSort(int a[], int size) {
    cout << "Merge Sorted Array ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// For Quick Sort Algorithm
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
// Recursive part for Quick Sort
void QuickSort(int a[], int low, int high) {
    if (low < high) {   // Condion for recursion
        int pivotIndex = Partion(a, low, high); // Return the pivot index each time
        QuickSort(a,low,pivotIndex - 1);    // Recursion
        QuickSort(a,pivotIndex + 1,high);    // Recursion
    }
}
// printing Quick Sort
void printQuickSort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
// Printing Original Array insert by user
void printOriginalArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n; // This will be size of array
    cout << "Enter the size of Array you want to insert " <<endl;
    cin >> n; // storing value/size in n

    int arr[n]; // Implementing size of array

    // Asking to user for value each time
    for (int i = 0; i < n; i++) {
        cout << "Enter the value " ;
        cin >> arr[i];
    }

    //Original Array
    cout << "Original Array : ";
    printOriginalArray(arr,n);

    //Function Call for MergeSort
    mergeSort(arr, 0, n-1);
    printMergeSort(arr, n);

    // Function call for Quick Sort
    QuickSort(arr,0,n - 1);
    cout << "Quick Sorted Array : ";
    printQuickSort(arr,n);

    return 0;
}