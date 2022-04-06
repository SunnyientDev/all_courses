#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

class Basic_class
{
	private:
		string obj_name;
		Basic_class* Head = nullptr;
		
	public:
		//properties
		vector <Basic_class*> Ders;
		vector <Basic_class*>::iterator it_Der;
		int Level;
		
		//constructors
		Basic_class(Basic_class* ptr_to_head);
		Basic_class(Basic_class* ptr_to_head, string obj_name)
		{
			int CurrentLevel = 0;
			setName(obj_name);
			this->Head = ptr_to_head;
			Basic_class* ptr = this;
			
			while(ptr->Head != nullptr)
			{
				ptr = ptr->Head;
				CurrentLevel += 1;
			}
			this->Level = CurrentLevel;
		}
		
		//methods
		string getName(){ return this->obj_name; }
		void setName(string obj_name){ this->obj_name = obj_name; }
		void setHead(Basic_class* Head){ this->Head = Head; }
		
		void ShowAns()
		{
			if(this->Level == 0) cout << this->getName() << endl;
			it_Der = Ders.begin();
			cout << this->getName() << "  ";
			
			while(it_Der != Ders.end())
			{
				cout << (*it_Der)->getName();
				if(it_Der + 1 != Ders.end()) cout << "  ";
				it_Der += 1;
			}
			
			if(this->Level < 1) cout << endl;
			it_Der = Ders.begin();
			
			while(it_Der != Ders.end())
			{
				if(!(*it_Der)->Ders.empty()) (*it_Der)->ShowAns();
				it_Der += 1;
			}
		}
		
		void newDer(Basic_class* Der) { this-> Ders.push_back(Der);}
		
		Basic_class* getDer(string obj_name)
		{
			it_Der = Ders.begin();
			while(it_Der != Ders.end())
			{
				if((*it_Der)->getName() == obj_name) return *it_Der;
				it_Der += 1;
			}
			return 0;
		}
};

class Class_1: public Basic_class
{
	public:
		Class_1(Basic_class* ptr_to_head, string obj_name): Basic_class(ptr_to_head, obj_name)
		{
		
		}
		
		Class_1(Basic_class* ptr_to_head): Basic_class(ptr_to_head)
		{
		
		}
};

class Class_2: public Basic_class
{
	public:
		Class_2(Basic_class* ptr_to_head, string obj_name): Basic_class(ptr_to_head, obj_name)
		{
		
		}
		
		Class_2(Basic_class* ptr_to_head): Basic_class(ptr_to_head)
		{
		
		}
};

int main(){
	string RootName; cin >> RootName;
	string obj_name;
	
	Basic_class Root(nullptr, RootName);
	Basic_class* Root_ptr = &Root;
	
	while(true)
	{
		cin >> RootName >> obj_name;
		if(obj_name == RootName) break;
		if(RootName != Root_ptr->getName()) Root_ptr = Root_ptr->getDer(RootName);
		if(Root_ptr->Level == 0) Root_ptr->newDer(new Class_1(Root_ptr, obj_name));
			else Root_ptr->newDer(new Class_2(Root_ptr, obj_name));
	}
	Root.ShowAns();
	return 0;
}
