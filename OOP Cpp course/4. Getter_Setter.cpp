// Функция доступа - это небольшая функция, которая предоставляет или изменяет значчение закрытой переменной.
#include <iostream>
using namespace std;

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;
 
public:
    void getDay() { cout << m_day; } // геттер для day
    void setDay(int day) { m_day = day; } // сеттер для day
 
    int getMonth() { return m_month; } // геттер для month
    void setMonth(int month) { m_month = month; } // сеттер для month
 
    int getYear() { return m_year; } // геттер для year
    void setYear(int year) { m_year = year; } // сеттер для year
};

int main(){
    Date today;
    today.setDay(1); today.getDay();
    return 0;
}

//OUTPUT: 1
