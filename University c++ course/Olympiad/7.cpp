/* Из 1 получить Х с помощью -9 или +9 */
#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c){
  if(c > 10000) return 1;
  else {
    if(a == b) return b;
    else if(a < b) return check(a + 9, b, c + 1);
    else return check(a - 9, b, c + 1); }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x;
  int res = check(1, x, 0);
  (res != 0) ? cout << "No": cout << "Yes";
  return 0;
}

/* Из 1 получить Х с помощью +8 или +9 */
#include <iostream>
#include <string>
using namespace std;

int check(int a, int b, int c){
  if(b - a < 8) return -1;
  else {
    if(a == b) return b;
    else if(b - a >= 9) return check(a + 9, b, c + 1);
    else if(b - a >= 8) return check(a + 8, b, c + 1);}
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x;
  int res = check(1, x, 0);
  (res == -1) ? cout << "No": cout << "Yes";
  return 0;
}
