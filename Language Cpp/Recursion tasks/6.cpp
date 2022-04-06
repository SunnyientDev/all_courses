/* F: Цифры числа справа налево
Дано натуральное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется). Разрешена только рекурсия и целочисленная арифметика.*/
#include <bits/stdc++.h>
using namespace std;

int print(int n){
  if(n < 10) return n;
  else {
    cout << n%10 << " ";
    return print(n/10);
  }
}

int main(int argc, const char * argv[]){
  int n; cin >> n;
  if(n < 10 && n > 0) cout << n;
  else if(n < 0) cout << "Input error";
  else cout << print(n);  
  return 0;
}
