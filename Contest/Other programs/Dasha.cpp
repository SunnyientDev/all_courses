#include <bits/stdc++.h>
using namespace std; 

bool find(vector <int> a, int number){
  bool res = false;
  for(int i = 0; i < a.size(); i++){
    if(number == a[i]){
      res = true;
      break;
    }
  }
  return res;
}

int main(){
    int current_number;
    int steps = 0, acc = 1000000; 
    float sum = 0;
    std:: vector <int> a; 
    bool condition = false;

    for(int j = 0; j < acc; j++){
      while(a.size() != 6){
        current_number = rand()%6 + 1;
        if(find(a, current_number) == false) a.push_back(current_number);
        steps++;
      }
      sum += steps;
      steps = 0;
      a.clear();
    }
    
    float result = sum/acc;
    cout << result;
}
