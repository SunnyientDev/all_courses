/*
Поинтереснее: Удалить в массиве все числа, которые повторяются более двух раз.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
  vector <int> b;

  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 1; j < n; j++){
      if(a[i] == a[j]) count++;
    }
    if(count < 2) b.push_back(a[i]);
    count = 0;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < b.size(); j++){
      if(a[i] == b[j]) cout << a[i];
    }
  }

  return 0;
}
