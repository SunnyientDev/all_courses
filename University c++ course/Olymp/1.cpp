#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int a[n];
  REP(i, 0, n) cin >> a[i];
  
  int count = 0;
  REP(i, 0, n-1){
    if(a[i] < a[i+1] && a[i]%7 == 0) count++;
  }

  cout << count;
  return 0;
}
