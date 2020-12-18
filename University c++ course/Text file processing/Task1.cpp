/* Преобразование разделителей: замена пробелов на другие(определенные) символы.*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  char oper; cin >> oper;
  ios::sync_with_stdio(0); cin.tie(0);  
  setlocale(LC_ALL, "rus");

//Создаем объект для записи в файл
ofstream Myfile("text.txt");
Myfile << "Here is text!";
Myfile.close();

char buff[10000]; // буфер промежуточного хранения считываемого из файла текста
ifstream fin("text.txt"); // открыли файл для чтения
 
fin >> buff; // считали первое слово из файла
cout << buff; // напечатали это слово

fin.getline(buff, 10000); // считали строку из файла
for(int i = 0; i < 10000; i++){
    if((int)buff[i] == 0) break;
    if((int)buff[i] == 32) buff[i] = oper; }
fin.close(); // закрываем файл
cout << buff << endl; // напечатали эту строку
}
