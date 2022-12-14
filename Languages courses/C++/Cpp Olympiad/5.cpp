#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string l; getline(cin, l);
  int c_K = 0, c_c = 0;
  REP(i, 0, l.size()){
    if(l[i] == 'K') c_K += 1;
    if(l[i] == 'c') c_c += 1;
  }
  cout << c_K + c_c;
  return 0;
}
