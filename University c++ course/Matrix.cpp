/*
Создать квадратную матрицу размера MxM, где M является целым числом из диапазона [2,5]. Конкретный размер матрицы задается пользователем.
Матрица должна содержать слова из 5ти букв английского алфавита, которые вводятся пользователем. Полученную матрицу обработать следующим образом. 
Каждое слово матрицы заменить на число, у которого в разряде десятков стоит количество гласных букв данного слова, а в разряде единиц – количество согласных букв данного слова. Каждую строку новой матрицы упорядочить по возрастанию. Результаты работы вывести на экран.
*/
#include <bits/stdc++.h>
using namespace std;

bool func(char x, string mas){
  bool ans = false;
  for(int i = 0; i < 12; i++){
    if(x == mas[i]) ans = true;
  }
  return ans;
}

//функция для сортировки по возрастанию
int comp1 (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main() {
int M; bool checker = true; 
cout << "Hi! :) \n";
cout << "Enter M [2,5]: ";
//---------------------Ввод верного значения M-----------------------
while (!(cin >> M) || (cin.peek() != '\n') || !(M >=2 && M <= 5)){
    if(M >=2 && M <= 5) break;
    else {cin.clear();
    while (cin.get() != '\n');
    cout << "Error 1. Enter another M:" << "\a"<< endl;}
}
    cout << " You entered M = " << M << "\n";
    cout << "Please enter " << M*M << " five-dimensional words, which consist of english words:" << "\n";
string glas = "AEIOUYaeiouy"; char a[M][M][5]; char x;

//-----------------------Формирование матрицы-----------------------
if(M >= 2 && M <= 5){
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        for(int k = 0; k < 5; k++){ cin >> x; 
          if(((int)x >=65 && (int)x <= 90) || ((int)x >=97 && (int)x <= 122)) a[i][j][k] = x;
            else{ checker = false; break;}
          }
      }
    }

  if(checker == false) cout <<"Input error";
  else{
    cout << "Current matrix view: " << "\n";
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        for(int k = 0; k < 5; k++) cout << a[i][j][k]; cout << " ";
      } 
      cout << "\n";
    }

int d[M][M], e[M][M];
for(int i = 0; i < M; i++)
  for(int j = 0; j < M; j++){d[i][j] = 0; e[i][j] = 0;}
if(checker == true){

    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        for(int k = 0; k < 5; k++){ 
          if(func(a[i][j][k], glas) == false) e[i][j]++;
            else d[i][j]++;
        }
      }
    }

    int b[M][M];
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        b[i][j] = d[i][j]*10 + e[i][j];
      }
    } 

cout << "\n";
  cout << "Next transformation (without sort): " << "\n";
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        cout << b[i][j] << " ";
      }
      cout << "\n";
    } 

cout << "\n";
  cout << "Next transformation (with sort): " << "\n";
     for(int i = 0; i < M; i++){
  qsort (b[i], M, sizeof(int), comp1);}

    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        cout << b[i][j] << " ";
      }
      cout << "\n";
    }   
}
  }
}
return 0;
}
