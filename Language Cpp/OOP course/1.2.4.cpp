#include <iostream>
using namespace std;

class Calc
{
  public:
  int res1, res2, res3;
  int num1, num2, num3, num4; char sigh1, sigh2, sigh3;
  
  Calc(int n1, int n2, int n3, int n4, char s1, char s2, char s3)
  {
    num1 = n1; num2 = n2; num3 = n3; num4 = n4;
    sigh1 = s1; sigh2 = s2; sigh3 = s3; 

  res1 = func(num1, num2, sigh1);
  res2 = func(res1, num3, sigh2);
  res3 = func(res2, num4, sigh3);
  }

  int func(int num1, int num2, char sigh){
  int res;
  if(sigh == '+') res = num1 + num2;
  else if(sigh == '-') res = num1 - num2;
  else if(sigh == '*') res = num1 * num2;
  else if(sigh == '%') res = num1 % num2; 
  return res;
  }

  void print(){
    cout << res3;
  }
};

int main() {
int num1, num2, num3, num4; char sigh1, sigh2, sigh3;
cin >> num1 >> sigh1 >> num2 >> sigh2 >> num3 >> sigh3 >> num4;
Calc obj = Calc(num1, num2, num3, num4, sigh1, sigh2, sigh3);
obj.print(); return 0;
}
