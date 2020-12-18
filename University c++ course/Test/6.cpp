/*
6. Сортировка и поиск

Уметь любым способом отсортировать массив. Создаем массив на 30 ячеек, выводим на экран. Затем ниже выводим на экран отсортированный вариант. Также выводим максимальный или минимальный элемент массива. Решение не прилагаю.
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){  
    int i, key, j;  
    for (i = 1; i < n; i++){  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key){  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void printArray(int arr[], int n){  
    int i;  
    for (i = 0; i < n; i++) cout << arr[i] << " ";  
    cout << "\n"; 
}  
  
int main(){  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
}  
