/* Найти вхождение строки в подстроку */

#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string a; getline(cin, a);
  string b; getline(cin, b);

vector <int> ind; int len = 0;
  for(int i = 0; i < a.size() - b.size()+1; i++){
    if(a[i] == b[0] && a[i+1] == b[1]){
      for(int j = 0; j < b.size(); j++){
        if(a[i+j] == b[j]) len += 1;
      }
    }
    if(len == b.size()){ ind.push_back(i); len = 0;}
  }

  for(int i = 0; i < a.size(); i++) cout << i << " "; cout << "\n";
  for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << "\n";
  cout << "\n";
  for(int i = 0; i < b.size(); i++) cout << i << " "; cout << "\n";
  for(int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << "\n";
  
  cout << "\n";
  if(ind.size() != 0){
    for(int i = 0; i < ind.size(); i++) cout << ind[i] << " ";
  } else cout << "No string";
}
