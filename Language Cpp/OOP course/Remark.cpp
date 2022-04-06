#include <iostream>
using namespace std;

class Basic
{
    public:
    int size;
    int func(int a){
        return a;
    }
};

class Der1: public Basic
{
    public:
    int func(int a){
        return a+1;
    }
};

int main(){
    Der1 *obj = new Der1;
    obj->size = 2;
    cout << obj->Der1::func(obj->size);
}
