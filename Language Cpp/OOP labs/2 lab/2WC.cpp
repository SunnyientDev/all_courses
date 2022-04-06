#include <iostream>
#include <iomanip>
#include <vector> //инструменты для работы с форматированием вывода
using namespace std;

class Basic {
public:
  int State, ClassName; 
  string ObjectName;

	Basic* RootObject, * Root, * ptr = 0;

	vector<Basic*> Ders;
	vector<Basic*>::iterator it;

	Basic(string ObjectName, int State) {
    this->State = State; this->ObjectName = ObjectName;
  }

	void setname(string ObjectName){ this->ObjectName = ObjectName; }
  string getname(){ return ObjectName; }

	Basic* ObjectSearch(string ObjectName) {
    if(this->ObjectName == ObjectName) return this;
    
    if(!Ders.empty()){
      it = Ders.begin();
      while (it != Ders.end()){
        ptr = (*it)->ObjectSearch(ObjectName);
        if(ptr != 0) break;
        it++;
      }
      return ptr;
    }
    return 0;
  }

int i = 0;

	void Print(){
    cout << "\n";
    for(int it = 0; it < i * 4; it++) cout << " ";
    cout << this->ObjectName;
    if (!Ders.empty()) for (it = Ders.begin(); it < Ders.end(); it++) (*it)->Print();
  }

	void Check(int State){
    if (!Ders.empty()) for (it = Ders.begin(); it < Ders.end(); it++) (*it)->Check(State);
  }

  void Add(string ObjectName, int ClassName, int State);
};

class Class_2 : public Basic {
public:
	Class_2(string ObjectName, int State) :Basic(ObjectName, State) {
	}
};

class Class_3 : public Class_2 {
public:
	Class_3(string ObjectName, int State):Class_2(ObjectName, State) {
	}
};

class Class_4 : public Class_3 {
public:
	Class_4(string ObjectName, int State):Class_3(ObjectName, State) {
	}
};

class Class_5 : public Class_4 {
public:
	Class_5(string ObjectName, int State):Class_4(ObjectName, State) {
	}
};

class Class_6 : public Class_5 {
public:
	Class_6(string ObjectName, int State):Class_5(ObjectName, State) 
  {
	}
};

void Basic::Add(string ObjectName, int ClassName, int State) {
	switch (ClassName) {
	case 2:
		Ders.push_back(new Class_2(ObjectName, State));
	  break;
	case 3:
		Ders.push_back(new Class_3(ObjectName, State));
	  break;
	case 4:
		Ders.push_back(new Class_4(ObjectName, State));
	  break;
	case 5:
		Ders.push_back(new Class_5(ObjectName, State));
	  break;
	case 6: 
		Ders.push_back(new Class_6(ObjectName, State));
	  break;
	}

	it = Ders.end() - 1; (*it)->Root = this;
	Basic* j = (*it);
	while (j->Root != 0){ j = j->Root; (*it)->i++; }
};

int main() {
  int State, ClassNum; //переменные состояния и номера класса
  string RootName, ObjectName; //переменные имени корня и объекта в нем
	cin >> RootName; //ввод имени главного корневого имени

	Basic* RootObject = new Basic(RootName, 1); //главный корень
	Basic* PtrToRoot = RootObject; //указатель на этот корень
	
  while(true){
		cin >> RootName; //ввод текущенго корня
		if (RootName == "endtree") break; 
		else {
			if (PtrToRoot->getname() != RootName) PtrToRoot = RootObject->ObjectSearch(RootName); //если имена корней не совпадают
            //указатель на объект в этом корне вернется с функцией ObjectSearch
			cin >> ObjectName >> ClassNum >> State; //ввод имени текущего объекта, его класса и состояния
            PtrToRoot->Add(ObjectName, ClassNum, State); //добавить объект чеерз указатель на корень
		}
	}
	
  cout << "Object tree";
	RootObject->Print();
	return 0;
}
