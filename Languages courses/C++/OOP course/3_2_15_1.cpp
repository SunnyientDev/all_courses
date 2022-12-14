#include <iostream>
#include <cmath>
using namespace std;

class Type2;

class Type1
{
  public:
    int prop;
  
  Type1(int p)
  {
    prop = p;
  }
    friend void compare(Type1 &type1, Type2 &type2);
};

class Type2
{
  public:
    void set(int prop1, int prop2)
    {
      m_prop1 = prop1; m_prop2 = prop2;
    }

    float get()
    {
      return m_prop1; 
      return m_prop2;
    }
  friend void compare(Type1 &type1, Type2 &type2);

  private:
    int m_prop1, m_prop2;
};


void compare(Type1 &t1, Type2 &t2){
  if(t1.prop >= t2.m_prop1 && t1.prop >= t2.m_prop2) cout << "max = " << t1.prop;
  else if(t1.prop <= t2.m_prop2 && t2.m_prop1 <= t2.m_prop2) cout << "max = " << t2.m_prop2;
  else if(t1.prop <= t2.m_prop1 && t2.m_prop1 >= t2.m_prop2) cout << "max = " << t2.m_prop1;
}

int main(){
  int num1, num2, num3;
  cin >> num1 >> num2 >> num3;
  Type1 obj1(num1);
  Type2 obj2; obj2.set(num2, num3);
  
  compare(obj1, obj2);
  return 0;
}
