/*
Двумерные массивы

Заполнить двумерный массив случайными  числами от 10  до 100. Посчитать сумму элементов отдельно в каждой строке и определить номер строки,  в которой эта сумма максимальна.
*/
#include<iostream> 
#include <random> 
using namespace std; 

int main (){
int n, m; cin >> n >> m;    
int a[n][m];

for(int i = 0; i < n; i++){
  for(int j = 0; j < m; j++) a[i][j] = 10 + rand()%101;
}

int b[n]; for(int i = 0; i < n; i++) b[i] = 0;

for(int i = 0; i < n; i++){
  for(int j = 0; j < m; j++) b[i] += a[i][j];
  cout << b[i] << " ";
}

int max = b[0];
for(int i = 1; i < n; i++){
  if(max < b[i]) max = b[i];
}

cout << max;
return 0;
}  
