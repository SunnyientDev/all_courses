#include <iostream>
#include <vector>
using namespace std;

class Basic
{
	public:
		int size, Min, Sum;
    bool cond = true;
		vector <int> arr;
		int x;
		
		void in_out()
		{
			cin >> size;
			if(size >= 1 && size <= 100)
			{
				for(int i = 0; i < size; i++)
				{
					cin >> x;
					if(x >= -100 && x <= 100) arr.push_back(x);
				}
			} else {cout << "Error"; cond = false;}
		}
};

class Der1 : public Basic
{
	public:
		int func(vector <int> arr)
		{
      int res;
      if(cond == true){
			res = arr[0];
			for(int i = 1; i < arr.size(); i++)
			{
				res -= arr[i];
			}} else res = 0;
			return res;
		}
};

class Der2 : public Der1
{
	public:
		int func(vector <int> arr)
		{
      int res;
      if(cond == true){
			res = arr[0];
			for(int i = 1; i < arr.size(); i++)
			{
				res += arr[i];
			}} else res = 0;
			return res;
		}
};

class Der3 : public Der2
{
	public:
		void in_out()
		{
			Basic::in_out();
      if(cond == true){
			Min = Der1::func(arr);
			Sum = Der2::func(arr);
			
			cout << "Array dimension: " << size << "\n";
			cout << "The original array:";
			for(int i = 0; i < arr.size(); i++)
			{
				printf("%5d", arr[i]);
			}
			cout << "\n" << "Min: " << Min;
			cout << "\n" << "Sum: " << Sum;
      }
		}
};

int main(){
	Der3 *ps = new Der3;
	ps->Der3::in_out();
	return 0;
}
