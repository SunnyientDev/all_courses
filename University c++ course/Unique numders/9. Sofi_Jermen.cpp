/*
Числа Софи Жермен
В теории чисел простое число Софи Жермен — это такое простое число p, что число 2p + 1 также простое.
Задание: найдите и напечатайте все числа Софи Жермен в интервале 
[m, n].
*/
#include <iostream> 
using namespace std; 

bool prost(int n){
  if(n < 2) return false;
  else {
    int count = 0;
    for(int i = 2; i < n; i++){
      if(n%i == 0) count++;
    }
    if(count != 0) return false;
    else return true;
  }
}

int main(){
int m, n; cin >> m >> n;

for(int i = m; i <= n; i++){
  if(prost(i) == true && prost(2*i+1) == true) cout << i << " " << 2*i+1 << "\n"; 
}

return 0;
}
