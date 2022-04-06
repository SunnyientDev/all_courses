/*
Условный оператор
Пользователь вводит порядковый номер пальца руки. 
Необходимо показать его название на экран.
PS Также очень рекомендую обратить внимание на задачу из презентации.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string a[5] = {"мезинец", "безымянный", "средний", "указательный", "большой"};
  int x; cin >> x;
  
  if(x == 1 or x == 10) cout << a[0];
  if(x == 2 or x == 9) cout << a[1];
  if(x == 3 or x == 8) cout << a[2];
  if(x == 4 or x == 7) cout << a[3];
  if(x == 5 or x == 6) cout << a[4];

  return 0;
}
