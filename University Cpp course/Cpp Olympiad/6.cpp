#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string l; getline(cin, l);

  bool ans1 = false, ans2 =  false, ans3 = false;
  if(l.size() >= 12) ans1 = true;

  REP(i, 0, l.size()){
     if((int)l[i] >= 65 && (int)l[i] <= 90) ans2 = true;
     if((int)l[i] >= 97 && (int)l[i] <= 122) ans3 = true;
  }
if(ans1*ans2*ans3 == true) cout << "YES";
  else cout << "NO";
  return 0;
}
