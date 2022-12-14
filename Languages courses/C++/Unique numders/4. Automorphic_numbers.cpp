/*
Автоморфные числа
Автоморфным называется число, равное последним цифрам своего квадрата.
Например: 5 и 25 (52=25), 25 и 625 (252=625)
Задание: найдите и напечатайте все автоморфные числа в интервале 
[m, n].
Пример: на интервале [1,10000] найдены 1, 1; 5, 25; 6, 36; 25, 625; 76, 5776.
*/
#include<iostream> 
#include <cmath>
using namespace std; 

int val(int i, int n){
  if(i < 10) return n + 1;
  else return val((i-i%10)/10, n + 1);
}

int main(){
  int m, n; cin >> m >> n; 
  int size;
  for(int i = m; i <= sqrt(n); i++){
    size = val(i*i, 0);
    for(int j = 0; j <= size; j++){
      if(i == (i*i)%(int)(pow(10, size-j))) cout << i << ", " << i*i << "; ";
    }
  }
return 0;
}
