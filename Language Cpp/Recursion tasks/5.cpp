/*E: Сумма цифр числа
Дано натуральное число N. Вычислите сумму его цифр.
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется).*/
#include <bits/stdc++.h>
using namespace std;

int func(int n, int sum){
  if(n < 10) return sum + n;
  else return func(n/10, sum + n%10);
}

int main(int argc, const char * argv[]){
  int n; cin >> n;
  cout << func(n, 0);
  return 0;
}
