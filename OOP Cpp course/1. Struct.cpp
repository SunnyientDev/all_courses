// Структуры могут хранить только данные без поведения, поэтому не явл-ся частью ООП
#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
};

void print(Date &date){
    cout << date.day<< "/" << date.month << "/" << date.year;
}

int main() {
    Date today {12, 12, 2012};
    print(today);
    return 0;
}

//OUTPUT: 12/12/2012 
