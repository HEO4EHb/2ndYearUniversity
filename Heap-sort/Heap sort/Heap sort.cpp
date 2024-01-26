#include <iostream>
using namespace std;

void heap(int arr[], int n, int i) {
    // находим наибольшее число по всему древу
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Свапаем и продолжаем менять древо если корень не является наибольшем числом
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

// главная функция
void heapSort(int arr[], int n) {
    // создаём пирамида или древо (max heap) то есть родитель всегда больше отпрыска
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        // вызываем heap чтобы опять найти максимальный элемент в корне
        heap(arr, i, 0);
    }
}

// Функция для печати 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
    int arr[] = { 1, 12, 9, 5, 6, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}