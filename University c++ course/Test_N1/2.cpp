#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x; 
  int count = 0;
  while(x != 0){
    if(x%19 == 0) count++;
    cin >> x;
  }
  cout << count;
  return 0;
}
