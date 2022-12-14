#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int a[n];
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) if(i%5 == 0 ) cout << a[i] << " \n";
  return 0;
}
