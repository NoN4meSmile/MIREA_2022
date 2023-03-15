#include <iostream>
#include "rational.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");

	int size;
	cout << "¬ведите количество дробей -> "; cin >> size;
	cout << "\n";
	rational* arr = new rational[size];
	int a, b;

	cout << "¬водить числа нужно строго через пробел\n";
	for (int i = 0; i < size; i++)
	{
		cout << "¬ведите числитель и знаминатель дроби номер " << i + 1 << " : "; cin >> a >> b;
		(arr[i]).set(a,b);
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\nƒробь номер " << i + 1 << " : ";
		(arr[i]).show();
	}
	cout << "\n";

	delete[] arr;

	return 0;
}