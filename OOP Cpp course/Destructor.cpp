#include <iostream>
#include <cassert>
 
class Massiv
{
private:
	int *m_array;
	int m_length;
 
public:
	Massiv(int length) // конструктор
	{
		assert(length > 0);
 
		m_array = new int[length];
		m_length = length;
	}
 
	~Massiv() // деструктор
	{
		// Динамически удаляем массив, который выделили ранее
		delete[] m_array ;
	}
 
	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }
 
	int getLength() { return m_length; }
};
 
int main()
{
	Massiv arr(15); // выделяем 15 целочисленных значений
	for (int count=0; count < 15; ++count)
		arr.setValue(count, count+1);
 
	std::cout << "The value of element 7 is " << arr.getValue(7);
 
	return 0;
} // Объект arr удаляется здесь, поэтому деструктор ~Massiv() вызывается тоже здесь
