#include <iostream>
using namespace std;

class Number
{
    private:
        int m_num1, m_num2;
    
    public:
        Number()
        {
            m_num1 = 1; 
            m_num2 = 2;
        }
        void print(){ cout << m_num1 << m_num2; }
};

int main(){
    Number num; num.print();
    return 0;
}

//OUTPUT: 12
