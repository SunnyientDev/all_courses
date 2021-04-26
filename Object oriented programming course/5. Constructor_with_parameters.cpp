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
        
        Number(int n1, int n2)
        {
            m_num1 = n1; 
            m_num2 = n2;
        }
        
        void print(){ cout << m_num1 << m_num2 << "\n"; }
};

int main(){
    Number num1; 
    num1.print();
    
    Number num2(3,4);
    num2.print();
    return 0;
}

//OUTPUT: 12
//        34
