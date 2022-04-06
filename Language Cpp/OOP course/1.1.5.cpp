#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie();
  int N; cin >> N;
  
  if(N < 10 && N > 0){
    int pos = 1;
    while(pos-1 != N){
      for(int i = 1; i <= pos; i++){ cout << i; if(i != N) cout << " "; }
      cout << "\n"; pos++;
    }
  } else cout << "N is wrong: " << N;

return 0;
}
