#include <algorithm>
using namespace std;

class Variables
{
    public:
    int size;
        Variables(int n) { Items = new int[n]; size = n; 
                for(int i = 0; i < n; i++){ cin >> Items[i]; }
        }
        
        void move(){
            cout << "Первая строка: \n";
            cout << "N = " << size;
            cout << "\n";
            cout << "Вторая строка (исходный порядок следования элементов): \n";
            for(int i = 0; i < size; i++){
               cout << Items[i]; if(i+1 < size) cout << " ";
            }
                        cout << "\n";
            cout << "Третья строка (порядок следования элементов после разворота): \n";
for (int i  = 0; i < size / 2; i++)
 swap(Items[i], Items[size - i - 1]);
            for(int i = 0; i < size; i++){
               cout << Items[i]; if(i+1 < size) cout << " ";
            }
        }
        ~Variables(){ delete Items; }
        int* Items;
};

int main(){
  setlocale(LC_ALL, "rus");
  ios::sync_with_stdio(0); cin.tie();
  cout << "Первая строка: \n";
  cout << "N = "; int n; cin >> n;
  if(n <= 10 && n > 0){
    cout << "Вторая строка: \n";
    Variables VO = Variables(n);    
    VO.move(); 
  } else cout << "Input Error";
}
