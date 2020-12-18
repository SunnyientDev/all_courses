#include <iostream>
using namespace std;

class Class1
{
	public:
		int a1, x, res; 
		
		virtual int func(int x)
		{
			res = a1*x;
			return res;
		}
};

class Class2 : public Class1
{
	public:
	int a2; 
		int func(int x)
		{
			res = a1*x + a2*x*x;
			return res;
		}
};

class Class3 : public Class2
{
	public:
	int a3;
		int func(int x)
		{
			res = a1*x + a2*x*x + a3*x*x*x;
			return res;
		}
};

class Class4 : public Class3
{
	public:
	int a4;
		Class4(int a1, int a2, int a3, int a4)
		{
			this -> a1 = a1;
			this -> a2 = a2;
			this -> a3 = a3;
			this -> a4 = a4;
		}
		
		int func(int x)
		{
			res = a1*x + a2*x*x + a3*x*x*x + a4*x*x*x*x;
			return res;
		}
};

int main(){
	int a1, a2, a3, a4, x, class_num;
	cin >> a1 >> a2 >> a3 >> a4;
	Class4 *ps = new Class4(a1, a2, a3, a4);
	
	cout << "a1 = " << a1 << "    a2 = " << a2 << "    a3 = "  << a3 << "    a4 = "  << a4 << "\n";

	while(true)
	{
		cin >> x;
		if(x == 0) break;
		
		cin >> class_num;			
		cout << "Class " << class_num << "    F( " << x << " ) = ";
			
		switch(class_num)
		{
			case 1:
				cout << ps->Class1::func(x) << "\n";
				break;
					
			case 2:
				cout << ps->Class2::func(x) << "\n";
				break;
						
			case 3:
				cout << ps->Class3::func(x) << "\n";
				break;
						
			case 4:
				cout << ps->Class4::func(x) << "\n";
				break;
			default: break;
		}
	}
	return 0;
}
