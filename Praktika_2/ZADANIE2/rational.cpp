#include "rational.h"
#include <iostream>

using namespace std;

void rational::set(int a1, int b1)
{
	if (b1 == 0) { a = 0; b = 0; }
	else if (a1 % b1 == 0) { a = a1 / b1; b = 1; }
	else
	{
		a1 = a1 % b1;
		double d = NOD(a1, b1);
		a = a1 / d;
		b = b1 / d;
	}
}
void rational::show()
{
	cout << a << "/" << b;
}
