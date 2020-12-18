#include <iostream>
#include <vector>
using namespace std;

class Basic 
{
  public:
  int size;
  vector <int> arr;
  int x;
  int Min; int Sum;

  void in_out(){   
      cin >> size;

      if(size >= 1 && size <= 100){
        cout << "The original array: ";
        for(int i = 0; i < size; i++){ 
          cin >> x; 
          if(x >= -100 && x <= 100) arr.push_back(x); 
        }
      } else cout << "Error";
  }
};

class Der1 : public Basic
{
  int func(vector <int> arr){
    int res = arr[0];
    for(int i = 1; i < arr.size(); i++){
      res -= arr[i];
    }
    return res;
  }

public:
  void impactMin(){
    Min = func(arr);
  }
};

class Der2 : public Der1
{
  int func(vector <int> arr){
    int res = arr[0];
    for(int i = 1; i < arr.size(); i++){
      res += arr[i];
    }
    return res;
  }

public:
  void impactSum(){
    Sum = func(arr);
  }
};

class Der3 : public Der2
{
  public:
  
  
  void in_out(){
    cout << "Array dimension: " << size << "\n";
    cout << "The original array:";
    for(int i = 0; i < arr.size(); i++){
      printf("%5d", arr[i]);
    }
    impactSum();
    impactMin();
    cout << "\n" << "Min: " << Min << "\n";
    cout << "\n" << "Sum: " << Sum << "\n";
  }
};

int main(){
  Der3 *ps = new Der3;
  ps->Der3::in_out();
return 0;
}
