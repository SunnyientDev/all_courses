#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

class Basic {
  protected:
    ifstream OutFile;
    string Text;

  public:
    void Print(){
      OutFile.open("field.txt");
      for(int i = 0; i < 10; i++){ getline(OutFile, Text); cout << Text << endl; }
      OutFile.close();
    }
};

class SetCoord {	
  public:
    int x, y;
    void SetCoordinate(int x, int y){ this->x = x; this->y = y; }
};

class SetSym {
	ofstream in;
	ifstream Basic;

	char Letter = ' '; char Matrix[10][10];
	vector <int> Coordinates; vector<char> Symbols;

	public:
	void AddSymbol (char Symbol){
		this->Letter = Symbol;
		if (!((Letter > 64 and Letter < 91) or (Letter < 123 and Letter>96))) Symbols.push_back(Letter);
	}

	void SetSymbol(int x, int y){
		if (x > 10 or x < 1 or y>10 or y < 1){ Coordinates.push_back(x); Coordinates.push_back(y); }
		else {
			Basic.open("field.txt");
			for (int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++) Basic >> Matrix[i][j];
			}
			Basic.close();

			if (((Letter > 64 and Letter < 91) or (Letter < 123 and Letter>96))) Matrix[x - 1][y - 1] = Letter;
      in.open("field.txt");
			
			for (int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++) in << Matrix[i][j];
				in << endl;
			}
			in.close();
		}
	}

	void PrintAnswer(){
		for (int i = 0; i < Coordinates.size() / 2; i++)
		cout << "Coordinate is wrong ( " << Coordinates[i*2] << ", " << Coordinates[i*2 + 1] <<" )"<< endl;

		if (Symbols.size() != 0){
			cout << "Not a letter of the Latin alphabet: " << Symbols[0];
			for (int i = 1; i < Symbols.size(); i++) cout << endl << "Not a letter of the Latin alphabet: " << Symbols[i];
		}
	}
};

int main(){
	ofstream in; in.open("field.txt");
	int x, y; char Symbol;

	Basic Object_1;
	SetCoord Object_2;
	SetSym Object_3;

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) in << 8;
		in << endl;
	}

	do {
		cin >> x >> y ;
		if (x == 0 || y == 0)break;
		else {
			Object_2.SetCoordinate(x, y); 
      cin >> Symbol;
			Object_3.AddSymbol(Symbol); Object_3.SetSymbol(Object_2.x, Object_2.y);
		}
	} while (x != 0 && y != 0);
	Object_1.Print();
	Object_3.PrintAnswer();
}
