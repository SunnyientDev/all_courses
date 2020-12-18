/*
Одномерные массивы
Попроще: Заполнить массив из 50-ти элементов нечётными числами от 1 до 99. 
*/
#include <iostream>
#include <random>
using namespace std;

bool prov(int a){
  if(a < 2) return false;
  else{ 
    int n = 0;
    for(int i = 2; i < a; i++){
      if(a%i == 0) n++;}
  if(n == 0) return true;
  else return false;
  }
}

int main() {
int a[50]; int x;
for(int i = 0; i < 50; i++){
  x = 1 + rand()%99;
  while(prov(x) == false){
   x = 1 + rand()%99;
  }
  cout << x << " ";
}
  return 0;
}
