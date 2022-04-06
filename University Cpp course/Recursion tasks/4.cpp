/*D: Точная степень двойки
Дано натуральное число N. Выведите слово YES, если число N является точной степенью двойки, или слово NO в противном случае.
Операцией возведения в степень пользоваться нельзя!*/
#include <bits/stdc++.h>
using namespace std;

int A(int n){
  if(n%2 == 0) return A(n/2);
  else if(n == 1) return 1;
  else return -1;
}

int main(int argc, const char * argv[]){
  int n; cin >> n;
  int ans;
  if(n > 0) ans = A(n);
  else cout << "Input error";

  if(ans == 1) cout << "YES";
  else if(ans == -1) cout << "NO";
  return 0;
}
