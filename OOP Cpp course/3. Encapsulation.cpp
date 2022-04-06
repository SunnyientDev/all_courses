# Здесь инкапсуляция предоставляет возможность изменения способа реализации классов, не нарушая при этом работу всех программ, которые их используют. 
#include <iostream>
using namespace std;

class Number
{
private:
    int m1_number;
public:
    void SetNumber(int num) { m1_number = num; }
    void PrintNumber(){ cout << m1_number; }
};
 
int main(){
    Number num;
    num.SetNumber(7); num.PrintNumber();
    return 0;
}

//OUTPUT: 7
