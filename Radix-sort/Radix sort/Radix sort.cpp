

#include <iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Функция  counsort'а для массива 
void countSort(int arr[], int n, int exp)
{
    int* output=new int[n]; //выходной массив
    int i, count[10] = { 0 };

    // Сохраняем количество вхождений в count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Изменяем count[i] так чтобы count[i] содержал
    //  позицию этой цифры в output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Заполняем массив output
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // копируем массив  output в  arr[], чтобы arr[] 
    // содержал отсортированные числа в зависимости от цифры
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


// сам Radix Sort
void radixsort(int arr[], int n)
{
    // Находим максимальное число чтобы знать количество цифр в нём
    int m = getMax(arr, n);

    // Делаем countsort для каждой цифры или "разряда".  вместо
    //передаваемого числа цифр,  передается exp.exp это  10^i
    // где i это рассматриваемая  Цифра числа
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

//ничего интересного
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);    
    radixsort(arr, n);
    print(arr, n);
    return 0;
}