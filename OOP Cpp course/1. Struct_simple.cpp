#include <iostream>
using namespace std;

struct Date
{
    int day, month, year;
};

int main() {
    Date today {12, 12, 2012};
    cout << today.day<< "/" << today.month << "/" << today.year;
    return 0;
}

//OUTPUT: 12/12/2012 
