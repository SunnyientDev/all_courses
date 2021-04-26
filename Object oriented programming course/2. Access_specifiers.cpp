#include <iostream>
using namespace std;
 
class DateClass // члены класса являются закрытыми по умолчанию
{
    int m_day; 
    int m_month;
    int m_year;
 
public:
    void setDate(int day, int month, int year){ // открыто, доступ имеет любой объект
        m_day = day;
        m_month = month;
        m_year = year; }
 
    void print(){ cout << m_day << "/" << m_month << "/" << m_year; }
};
 
int main()
{
    DateClass date;
    date.setDate(12, 11, 2018); date.print(); 
    return 0;
}

//OUTPUT: 12/11/2018
