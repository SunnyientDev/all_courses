/*
Числа-близнецы 
Числа-близнецы (парные простые числа) — пары простых чисел, отличающихся на 2.
Задание: найдите и напечатайте все числа-близнецы в интервале [m, n].
*/

#include <iostream> 
#include <vector>
using namespace std; 

bool prost(int n){
  if(n < 2) return false;
  else {
    int count = 0;
  for(int i = 2; i < n; i++) 
    if(n%i == 0) count++;
  if(count == 0) return true;
  else return false;
  }
}

int main(){
int m, n; cin >> m >> n;
vector <int> a;

for(int i = m; i <= n; i++){
  if(prost(i) == true) a.push_back(i);
}

for(int i = 0; i < a.size(); i++){
  if(a[i+1]-a[i] == 2) cout << a[i] << " " << a[i+1] << "\n";
}
return 0;
}
