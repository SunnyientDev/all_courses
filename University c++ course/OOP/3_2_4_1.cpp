#include <iostream>
using namespace std;

class Check
{
  public:
  Check(){
    cout << "Constructor \n";
  }

    ~Check(){
    cout << "Destructor";
  }

};

int main(){
  Check condition;
return 0;
}
