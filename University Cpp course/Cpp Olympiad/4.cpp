#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int fact(int x){
  if(x == 0 || x == 1) return 1;
    else return fact(x-1)*x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x;
  cout << fact(x);
  return 0;
}
