/*
Сортировка и поиск

Уметь любым способом отсортировать массив. Создаем массив на 30 ячеек, выводим на экран. Затем ниже выводим на экран отсортированный вариант. Также выводим максимальный или минимальный элемент массива. Решение не прилагаю.

Здесь прдетсавлена сортировка вставками.
*/
#include<iostream> 
#include <random> 
using namespace std; 

int main (){    
    int myarray[30];   
    for(int i = 0; i < 30; i++) myarray[i] = -100 + rand()%201;
    int n = 30;

    cout<<"\nInput list is \n";
    for(int i = 0; i < n; i++) cout << myarray[i] <<"\t";  

    for(int k = 1; k < n; k++){  
        int temp = myarray[k];  
        int j = k-1;  
        while(j >= 0 && temp <= myarray[j]){  
            myarray[j+1] = myarray[j];   
            j = j-1;  
        }  
        myarray[j+1] = temp;  
    }  

    cout<<"\nSorted list is \n";
    for(int i = 0; i < n; i++) cout << myarray[i] <<"\t";  
return 0;
}  
