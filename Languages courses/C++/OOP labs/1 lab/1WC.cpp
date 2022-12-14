#include <iostream>
#include <vector>
using namespace std;

class Object
{
public:
//properties
  int ObjectState;
	string ObjectName;
  
	Object* PtrRoot; //указатель на корневой объект
	vector <Object*> Ders; // вектор указателей объектов на головной объект 
	
//constructors
  Object(string ObjectName)
	{
    ObjectState = 1;
		this->ObjectName = ObjectName;
	}

	Object(string ObjectName, Object* PtrRoot, int ObjectState)
	{
		this->PtrRoot = PtrRoot; PtrRoot->Ders.push_back(this);
    this->ObjectName = ObjectName;
		this->ObjectState = ObjectState;
	}

//methods
	Object* ObjectSearch(string ObjectName)
	{
		static Object* PtrObject = 0; //указатель на некоторый объект на дереве

		for (Object* OneObject : Ders){
			if (OneObject->ObjectName == ObjectName){ PtrObject = OneObject; break; }
			OneObject->ObjectSearch(ObjectName);
		}
		return PtrObject;
	}

	void Print(){
		for (Object* OneObject : Ders){
			if (OneObject->ObjectState > 0) cout << "\nThe object " << OneObject->ObjectName << " is ready";
			else cout << "\nThe object " << OneObject->ObjectName << " is not ready";
			OneObject->Print();
		}
	}
};

class Class_2 : public Object
{
public:
	Class_2(string ObjectName, Object* PtrRoot, int ObjectState) : Object(ObjectName, PtrRoot, ObjectState)
	{

	}
};

class Class_3 : public Object
{
public:
	Class_3(string ObjectName, Object* PtrRoot, int ObjectState) : Object(ObjectName, PtrRoot, ObjectState)
	{

	}
};

class Class_4 : public Object
{
public:
	Class_4(string ObjectName, Object* PtrRoot, int ObjectState) : Object(ObjectName, PtrRoot, ObjectState)
	{

	}
};

int main(){
	string RootName; cin >> RootName; //имя корневого объекта
  Object* RootObject = new Object(RootName); // создание корневого объекта
	
  Object* Object1, * Object2, * Object3, * PtrObject = 0; //объявление указателей на объекты некоторого класса

	while(RootName != "endtree"){
		cin >> RootName; // ввод имени корневого объекта
		
    if (RootName == "endtree") break;
		else {
      int ClassNumber, ObjectState; string DerName;
			cin >> DerName >> ClassNumber >> ObjectState; // имя второст. объекта, номер класса и состояние объекта
			
      if (RootName != RootObject->ObjectName)	PtrObject = RootObject->ObjectSearch(RootName);
      //если имена головного и второго не совпают указатель на него равен указателю на объект, найденного в этом древе
			else PtrObject = RootObject; //иначе это же головной объект

			switch (ClassNumber){
			case 1:
				Object1 = new Class_2(DerName, PtrObject, ObjectState); //просто указываем на объект 2 класса 
				break;
			case 2:
				Object2 = new Class_3(DerName, PtrObject, ObjectState);
				break;
			case 3:
				Object3 = new Class_4(DerName, PtrObject, ObjectState);
				break;
			default:
				Object1 = new Object(DerName, PtrObject, ObjectState);
				break;
			}
		}
	}
	cout << "Test result\n";
	cout << "The object " << RootObject->ObjectName << " is ready";
	RootObject->Print();
  return 0;
}
