#include <iostream>
#include <vector>
using namespace std;

class Basic_Class 
{
	public:
	//properties
		string ObjectName;
		int Level = 0;
		Basic_Class* Head = nullptr;
		vector <Basic_Class*> Der = {};
		
	//setters, getters
		void SetName(string Name){ this->ObjectName = Name; }
		string GetName(){ return this->ObjectName; }
		
	//Show results
		void ShowAns(vector <Basic_Class*> Object)
		{
			int Current_Level = 0;
			if(this->Level == 0) cout << this->GetName();
			
			for(Basic_Class* it1: Object)
				if(it1->Level > Current_Level) Current_Level = it1->Level;
				
			for(int it1 = 0; it1 < Current_Level; it1++){
				for(Basic_Class* it2: Object){
					if(it2->Level == it1){
						if(!(it2->Der.empty())){
							cout << "\n" << it2->GetName();
							for(Basic_Class* it3: it2->Der) cout << "  " << it3->GetName();
						}
					}
				}
			}
		}
		
	//Constructors
		Basic_Class(Basic_Class* Pointer_to_Head, string Current_Name)
		{
			int Counter = 0;
			this->SetName(Current_Name);
			this->Head = Pointer_to_Head;
			Basic_Class* Current_Object = this;
			
			while(Current_Object->Head != nullptr){
				Current_Object = Current_Object->Head;
				Counter++;
			}
			
			this->Level = Counter;
			if(this->Head != nullptr) Head->Der.push_back(this);
		}
		
		Basic_Class(Basic_Class* Pointer_to_Head);
};

class Class_1: public Basic_Class
{
	public:
		Class_1(Basic_Class* Pointer_to_Head, string Current_Name): Basic_Class(Pointer_to_Head, Current_Name)
		{
		
		}
		
		Class_1(Basic_Class* Pointer_to_Head): Basic_Class(Pointer_to_Head)
		{
		
		}		
};

class Class_2: public Basic_Class
{
	public:
		Class_2(Basic_Class* Pointer_to_Head, string Current_Name): Basic_Class(Pointer_to_Head, Current_Name)
		{
		
		}
		
		Class_2(Basic_Class* Pointer_to_Head): Basic_Class(Pointer_to_Head)
		{
		
		}		
};

int main(){
	string ObjectName; cin >> ObjectName;
	string RootName;
	vector <Basic_Class*> Objects_Vector = {};
	
	Basic_Class Root(nullptr, ObjectName);
	Basic_Class* Pointer = &Root;
	Objects_Vector.push_back(Pointer);
	
	while(true){
		cin >> RootName >> ObjectName;
		if(ObjectName == RootName) break;
		for(Basic_Class* it1: Objects_Vector) if(it1->ObjectName == RootName) Pointer = it1;
		Class_1* Object = new Class_1(Pointer, ObjectName);
		Objects_Vector.push_back(Object);
	}
	Root.ShowAns(Objects_Vector);
	return 0;
}
