//определить возможно ли с помощью +-9 получить из 1 чило X
#include <bits/stdc++.h>
using namespace std;

bool fun1(int y, int x){
  if(y == x) return true;
  else if(y > x) return false;
  else if(y < x) return fun1(y+9, x);
}

bool fun2(int y, int x){
  if(y > x) return fun1(y-9, x);
  else if(y == x) return true;
  else if(y < x) return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x;
  int y = 1;

  bool ans1 = fun1(y, x);
  bool ans;

  if(ans1 == false){
    ans = fun2(y, x);
  }

  if(ans == true) cout << "YES";
    else cout << "NO";
  return 0;
}
