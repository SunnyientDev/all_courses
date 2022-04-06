/*
Числа Фибоначчи
Числами Фибоначчи называются члены ряда:
F(1)=F(2)=1;
F(n)=F(n-1)+F(n-2)  для n>=3.
*/

#include<iostream> 
using namespace std; 

int fib(int n){
  if(n == 1) return 1;
  else if(n == 2) return 1;
  else return fib(n-2) + fib(n-1);
}

int main(){
  int n; cin >> n;
  cout << fib(n);
return 0;
}
