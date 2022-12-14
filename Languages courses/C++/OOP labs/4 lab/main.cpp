#include <iostream>
#include "Basic.h"
using namespace std;

typedef void(Basic::* T_SIGNAL)(string&);
typedef void(Basic::* T_HANDLER)(string);

int main(){
	int State, ClassNum;
	string RootName, ObjectName; cin >> ObjectName;
	
	Basic* RootObject = new Basic(ObjectName, 1);
	Basic* PtrToRoot = RootObject;
	Basic* PtrToObject = nullptr;
	
	while(true){
		cin >> RootName;
		if(RootName == "endtree") break;
		if(PtrToRoot->GetName() != RootName)
		{
			PtrToRoot = RootObject->SearchObject(RootName);
			if(PtrToRoot == nullptr){ cout << "Head not found"; break; }
		}
		cin >> ObjectName >> ClassNum >> State;
		if(State > 0) PtrToRoot->Add(ObjectName, ClassNum, State);
	}
	
	cout << "Object tree\n"; RootObject->Print();
	cout << "Set connects\n";
	int Comlink;
	while(true){
		cin >> Comlink;
		if(Comlink == 0) break;
		
		cin >> RootName >> ObjectName;
		cout << Comlink << " " << RootName << " " << ObjectName << "\n";
		
		PtrToRoot = RootObject->SearchObject(RootName);
		PtrToObject = RootObject->SearchObject(ObjectName);
		PtrToRoot->SetConnection(M_SIGNAL(Basic::signal), PtrToObject, M_HANDLER(Basic::Handler));
	}
	
	cout << "Emit signals";
	string Word;
	while(true){
		cin >> ObjectName;
		if(ObjectName == "endsignals") break;
		cin >> Word; cout << "\n";
		PtrToRoot = RootObject->SearchObject(ObjectName);
		PtrToRoot->TransmitSignal(M_SIGNAL(Basic::signal), Word);
	}
}
