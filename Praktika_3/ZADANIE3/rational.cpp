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

rational operator + (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	int a, b;

	b = ok;

	a = a1 * k1 + a2 * k2;

	rational ans(a, b);

	return ans;

}
rational operator - (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	int a, b;

	b = ok;

	a = a1 * k1 - a2 * k2;

	rational ans(a, b);

	return ans;

}
rational& rational::operator ++ ()
{
	a = a + 1;
	set(a, b);

	return *this;
}
bool operator == (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	return (a1 * k1 == a2 * k2);

}
bool operator > (rational d1, rational d2)
{
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);

	int ok = d1.NOK(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;

	return (a1 * k1 > a2 * k2);

}