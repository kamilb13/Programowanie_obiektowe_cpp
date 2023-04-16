#include <iostream>

using namespace std;

// Funkcja sortuj¹ca przez algorytm b¹belkowy
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Funkcja sortuj¹ca przez wstawianie
template <typename T>
void insertionSort(T arr[], int n) {
    int i, j;
    T key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Funkcja sortuj¹ca przez quicksort
template <typename T>
void quickSort(T arr[], int left, int right) {
    int i = left, j = right;
    T tmp;
    T pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    int arr1[] = { 3, 5, 1, 9, 8, 6 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, n1);
    cout << "Sortowanie babelkowe: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int arr2[] = { 3, 5, 1, 9, 8, 6 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2);
    cout << "Sortowanie przez wstawianie: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int arr3[] = { 3, 5, 1, 9, 8, 6 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    quickSort(arr3, 0, n3-1);
    cout << "Sortowanie quicksort: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
}
