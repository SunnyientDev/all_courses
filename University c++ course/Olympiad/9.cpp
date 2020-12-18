#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ifstream fin;
  int num = 0;
  int min = 1000;

fin.open("input.txt");
while (!fin.eof()){
  fin >> num;
  if (num % 11 == 0 and num < min) min = num;
}

fin.close();
ofstream fout;
fout.open("output.txt");
fout << min;
fout.close();
return 0;
}
