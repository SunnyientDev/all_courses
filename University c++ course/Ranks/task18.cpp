#include <bits/stdc++.h>
using namespace std;

float fact(int N){
    if(N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * fact(N - 1); // делаем рекурсию.
}

float y(int k, int x){
  float f;
  if(k == 0) f = (fact(k+2)/(pow(k+1, 2)*pow(x, 2*k+2)));
  else f = y(k-1, x) + (fact(k+2)/(pow(k+1, 2)*pow(x, 2*k+2)));
  return f;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x; cin >> x;
  int k = 10; 
  cout << y(k, x);
}
