#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
//n - число лопастей
int n = 0;
do{
  n++;
} while(a+b*n < c);
  cout << n-1;
  return 0;
}
