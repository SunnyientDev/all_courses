#include "Basic.h"
using namespace std;

void Basic::Handler(string s){ cout << s; }
void Basic::signal(string& s){}
string Basic::GetName(){ return ObjectName; }

Basic::Basic(string ObjectName, int State){
	int Lay = 0;
	this->CurrentLay = Lay;
	this->ObjectName = ObjectName;
	this->State = State;
}

void Basic::Add(string ObjectName, int ClassNum, int State){
	switch(ClassNum){
		case 2: Ders.push_back(new Class_2(ObjectName, State)); break;
		case 3: Ders.push_back(new Class_3(ObjectName, State)); break;	
		default: break;
	}
	
	i = Ders.end() - 1; (*i)->Root = this;
	Basic* CurrentPtr = (*i);
	while(CurrentPtr->Root != nullptr){
		(*i)->CurrentLay++;
		CurrentPtr = CurrentPtr->Root;
	}
}

Basic* Basic:: SearchObject(string ObjectName){
	if(this->ObjectName == ObjectName) return this;
	if(!Ders.empty()){
		i = Ders.begin();
		while(i != Ders.end()){
			ptr = (*i)->SearchObject(ObjectName);
			if(ptr != nullptr) break;
			i++;
		}
		return ptr;
	}
	return nullptr;
}

void Basic::SetConnection(T_SIGNAL signal, Basic* Object, T_HANDLER handler){
	if(Relations.size() > 0){
		for(int i = 0; i < Relations.size(); i++){
			if(Relations[i]->Object == Object && Relations[i]->SignalPtr == signal && Relations[i]->HandlerPtr == handler) return;
		}
	}
	
	Connections* con = new Connections;
	con->HandlerPtr = handler;
	con->Object = Object;
	con->SignalPtr = signal;
	Relations.push_back(con);
}

void Basic::ResetConnection(T_SIGNAL signal, Basic* Object, T_HANDLER handler){
	if(Relations.size() > 0){
		for(int i = 0; i < Relations.size(); i++){
			if(Relations[i]->Object == Object && Relations[i]->SignalPtr == signal && Relations[i]->HandlerPtr == handler) Relations.erase(Relations.begin()+ i);
		}
	}
}

void Basic::TransmitSignal(T_SIGNAL signal, string s){
	T_HANDLER Hand;
	bool Condition = false;
	
	for(int i = 0; i < Relations.size(); i++){
		if(Relations[i]->SignalPtr == signal){
			Hand = Relations[i]->HandlerPtr;
			if(Condition) cout << "\n";
			cout << "Signal to " << Relations[i]->Object->ObjectName << " Text: " << ObjectName << " -> ";
			Condition = true; 
			(Relations[i]->Object->*Hand)(s);
		}
	}
}

void Basic::Print(){
	for(int i = 0; i < 4*CurrentLay; i++) cout << ' ';
	cout << ObjectName << "\n";
	if(!Ders.empty()){
		i = Ders.begin();
		while(i != Ders.end()){ (*i)->Print(); i++; }
	}
}
