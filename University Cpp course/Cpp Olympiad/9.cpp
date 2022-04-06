#define REP(i, a, b) for(int i = a; i < b; i++)
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ofstream fout("input.txt");

  string l; getline(cin, l);
  fout << l; // запись строки в файл
  fout.close(); // закрываем файл

  string line;
  ifstream inf("input.txt"); // окрываем файл для чтения
    if (inf.is_open()){
        while (getline(inf, line)) cout << line << std::endl;
    }
    inf.close();     // закрываем файл


}
