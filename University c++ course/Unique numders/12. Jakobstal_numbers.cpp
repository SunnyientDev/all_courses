/*
Числа Якобсталя
Числа Якобсталя определяются рекуррентным отношением
Задание: найдите и напечатайте все числа Нараньяны в интервале [m, n].
*/
#include <iostream> 
using namespace std; 

int jakob(int n){
  if(n == 0) return 0;
  else if(n == 1) return 1;
  else if(n > 1) return jakob(n-1)+2*jakob(n-2);
}

int main(){
int m, n; cin >> m >> n;
int c = 0;

while(jakob(c) < m) c++;
c++;
while(jakob(c) < n){
  cout << jakob(c) << " "; c++;
}
return 0;
}
