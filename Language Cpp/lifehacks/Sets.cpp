int main(){
    int n; cin >> n;
    int a[n]; time(NULL);
    set <int> m;

    for(int i = 0; i < n; i ++) {a[i] = rand()%100; m.insert(a[i]);}
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
cout << "\n";

    for(auto i : m) cout << i << " ";
}

int main(){
    int n; cin >> n;
    int a[n]; time(NULL);
    multiset <int> m;

    for(int i = 0; i < n; i ++) {a[i] = rand()%100; m.insert(a[i]); m.insert(a[i]);}
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
cout << "\n";

    for(auto i : m) cout << i << " ";
}
