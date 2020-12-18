#ifndef _BASIC_H
#define _BASIC_H

#pragma once
#include <iostream>
#include <vector>
#include <iterator> 
#include <iomanip>
using namespace std;

class Basic {
	Basic* Root = nullptr;
	string ObjectName;
	
	public:
		typedef void(Basic::* T_SIGNAL)(string&);
		typedef void(Basic::* T_HANDLER)(string);
	
		#define M_SIGNAL(sig_f)(T_SIGNAL)(&sig_f)
		#define M_HANDLER(hand_f)(T_HANDLER)(&hand_f)
		
		vector <Basic*> Ders;
		vector <Basic*>:: iterator i;
	
		struct Connections {
			T_HANDLER HandlerPtr; T_SIGNAL SignalPtr;
			Basic* Object;
		};
	
		vector <Connections*> Relations;
		Basic(string ObjectName, int State);
		
		string GetName();
		void Add(string ObjectName, int class_name, int State);
		
		Basic* SearchObject(string ObjectName);
		Basic* SearchPath(string path);
	
		void SetConnection(T_SIGNAL signal, Basic* Object, T_HANDLER handler);
		void ResetConnection(T_SIGNAL signal, Basic* Object, T_HANDLER handler);
		void TransmitSignal(T_SIGNAL signal, string s);
	
		virtual void signal(string &s);
		virtual void Handler(string s);
	
		void Print();
		int CurrentLay, State;
		Basic* ptr;
};

class Class_2: public Basic {
	public:
		Class_2(string ObjectName, int State): Basic(ObjectName, State) {};
};

class Class_3: public Basic {
	public:
		Class_3(string ObjectName, int State): Basic(ObjectName, State) {};
};

#endif //_BASIC_H
