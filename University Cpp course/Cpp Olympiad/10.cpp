#include <bits/stdc++.h> 
using namespace std; 

int main(){  
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s);
    int a, b;
    int i = 0; while(s[i] != 'x') i++;
    string a1; for(int j = 0; j < i; j++) a1 += s[j];
    a = stoi(a1);

    string b1; 
    for(int j = i+1; j < s.size()-1; j++) b1 += s[j];
    b = stoi(b1);
    cout << (-1)*(float)b/(float)a;
}  
