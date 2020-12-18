/*
Дано целое число n (вводится с клавиатуры). Вычислить: y = 1/sin(1) + 2/(sin(1)+sin(2)) ..
*/

#include <bits/stdc++.h>
using namespace std;

float sinus(int n){
  float sum = 0, sum_sin = 0;
  for(int i = 1; i <=n; i++){
    for(int j = 1; j <=i; j++){
      sum_sin += sin(j);
    }
  sum += i/sum_sin;
  sum_sin = 0;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  cout << sinus(n);
  return 0;
}
