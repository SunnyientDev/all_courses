#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    ofstream fout("cpp.txt"); string str;
    getline(cin, str);
    fout << str;
    fout.close();

    char buff[128]; str.clear();
    ifstream ifile;
    ifile.open("cpp.txt");
    ifile.getline(buff, 128);
    str = string(buff);
    cout << str << "\n";

    vector <int> b; string uf;
    int count = 1;
    for(int i = 0; i < str.size(); i++) if(str[i] == ' ') count++;

    int l = 0;
    for(int j = 0; j < count; j++) {
        while (str[l] != ' '){
            uf += str[l];
            l++;
        }
        b.push_back(atoi(uf.c_str())); uf = "0";
        l++;
    }

    for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
}
