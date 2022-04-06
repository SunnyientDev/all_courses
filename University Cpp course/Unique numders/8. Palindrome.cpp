/*
Простые палиндромы
Палиндромы – числа, читающиеся одинаково слева направо и справа налево.
Задание: найдите и напечатайте все простые палиндромы в интервале 
[m, n].
*/
#include <iostream> 
#include <string>
using namespace std; 

int main(){
int m, n; cin >> m >> n;
bool ans = true; 

for(int i = m; i <= n; i++){
  ans = true;
  string s = to_string(i);
  
  if(s.size()%2 != 0){
    int ind = s.size()/2;
    int i = 0;
      while(i != ind){
        if(s[i] != s[s.size()-i-1]) { ans = false; break;}
        i++;
      }
  }
  
  else {
    int ind = s.size()/2; //2
    int i = 0;
      while(i != ind){
        if(s[i] != s[s.size()-i-1]) { ans = false; break;}
        i++;
      }
    } 
if(ans == true) cout << i << " ";
}
return 0;
}
