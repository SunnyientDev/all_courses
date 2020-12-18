/*
Строки/файлы

Дан файл с текстом. Пользователь вводит несколько символов. Исключите из текстового файла заданные символы.
*/
#include<iostream> 
#include <string>
#include <fstream>
using namespace std; 

int main (){
setlocale(LC_ALL, "rus");
string s; getline(cin, s);
ofstream ofile("cpp.txt");
ofile << s;
ofile.close();

ifstream ifile("cpp.txt");
char buff[1000];
ifile.getline(buff, 1000);
ifile.close();

cout << buff;
return 0;
}  
