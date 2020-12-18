#include <iostream>
using namespace std;

class Calc
{
  public:
    int num1, num2;
    char sigh;

Calc(int n1, char s, int n2)
{
  num1 = n1; sigh = s; num2 = n2;
}

~Calc(){ }

int math(int n1, char s, int n2){
  int res;
  if(s == '+') res = n1 + n2;
  else if(s == '-') res = n1 - n2;
  else if(s == '*') res = n1 * n2;
  else if(s == '%') res = n1 % n2;
  return res;
}
};

int main(){
int counter = 0;
int num1, num2; char sigh;
int res;
cin >> num1 >> sigh >> num2;
Calc *obj = new Calc(num1, sigh, num2); 
res = obj->math(num1, sigh, num2);
delete obj;
counter++;

while(sigh != 'C'){
  cin >> sigh;
  if(sigh == 'C') break;
  counter++;
  cin >> num2;
  Calc *obj = new Calc(res, sigh, num2); 
  res = obj->math(res, sigh, num2);
  delete obj;
  if(counter%3 == 0) cout << res;
}

return 0;
}
