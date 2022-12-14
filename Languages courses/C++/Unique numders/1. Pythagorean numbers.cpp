/*
Пифагорово число (пифагорова тройка) — комбинация из трёх целых чисел (x,y,z), удовлетворяющих соотношению Пифагора: x2+y2=z2.
Задание: найдите и напечатайте все пифагоровы числа в интервале 
[m, n].
Примеры: 3,4,5	 6,8,10	9,12,15
*/
#include<iostream> 
#include <string>
#include <set>
using namespace std; 

int main (){
int m, n; cin >> m >> n;
set <int> myset;
for(int i = m; i <= n; i++){
  for(int j = m+1; j <= n; j++){
    for(int k = m+2; k <= n; k++){
      if(i*i+j*j == k*k) {myset.insert(i); myset.insert(j); myset.insert(k);}
    }
  }
}
    for(auto i : myset)
        cout << i << " ";

return 0;
}  
