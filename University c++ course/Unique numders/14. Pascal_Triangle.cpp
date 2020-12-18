/*
Треугольник Паскаля
*/
#include <iostream> 
#include <vector>
using namespace std; 

void tab(char a, int n) {
	for (int i = 0; i < n; i++) cout << a;
}

int func(vector <int> a, int i, int j){
  return a[i]+a[j];
}

int main(){

int n; cin >> n;
vector <int> a; vector <int> b;

if(n >= 1){
  a.push_back(1); 
  tab('\t', n);
  cout << a[0] << "\n";
  a.clear();
}

if(n >= 2){
  a.push_back(1); a.push_back(1);
  tab('\t', n-1);
  cout << a[0]; tab('\t', 2);
  cout << a[1] << "\n";
}

if(n > 2){
  for(int i = 3; i <= n; i++){
    b.clear(); b.push_back(1);
    for(int j = 0; j < a.size()-1; j++) b.push_back(func(a, j, j+1)); 
    b.push_back(1);
    tab('\t', n - i+1); 
    for(int j = 0; j < b.size(); j++){
      cout << b[j]; tab('\t', 2); 
    }
    cout << "\n";
    a = b;
  }
}
return 0;
}
