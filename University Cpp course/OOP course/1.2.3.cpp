#include <iostream>
using namespace std;

class Prop
{
	public:
	bool sigh = 0;
	Prop(int num){
	if(num < 0) sigh = 1;
		n = abs(num);
	}
	
	int count = 0; 
	void print(){
	cout << "n = "; if(sigh == 1) cout << "-";
	cout << n << "\n";
	if(n == 0) count = 1;
	else while(n > 0){ n /= 10; count++; }
	cout << "N = " << count;
	}
	private:
	long int n;
};

int main(){
	long int num; cin >> num;
	Prop obj = Prop(num);
	obj.print();
	return 0;
}
