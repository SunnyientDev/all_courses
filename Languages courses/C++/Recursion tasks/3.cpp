/*B: От A до B
Даны два целых числа A и В (каждое в отдельной строке). Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.*/
#include <bits/stdc++.h>
using namespace std;

int A(int m , int n){
  if(m == 0) return n + 1;
  else if (m > 0 && n == 0) return A(m-1, 1);
  else if (m > 0 && n > 0) return A(m-1, A(m, n-1));
}

int main(int argc, const char * argv[]){
  int m, n; cin >> m >> n;
  if(m > 0 && n > 0) cout << A(m,n);
  else cout << "Error";
  return 0;
}
