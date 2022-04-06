#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  setlocale(LC_ALL, "rus");
  int m; cin >> m;
  int c3, c4;
  c4 = m%3; c3 = (m - 4*c4)/3;

  if(m > 2 && m != 5){
    cout << c3 << " " << c4;
  } else cout << "Нет решений";
  return 0;
}
