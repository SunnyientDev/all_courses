#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int z, x, y = 0;
  int res;

cout << "Количестово туристов, гидов и вместительность "<<"\n";
cin >> x >> y >> z;

if (y / res < 2) cout << 0;
	else cout << res;

if ((x + y) % z == 0) res = (x + y) / z;
	else res = (x + y) / z + 1;

return 0;
}
