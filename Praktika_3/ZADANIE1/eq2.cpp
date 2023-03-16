#include "eq2.h"

void eq2::set(double a1, double b1, double c1)
{
	a = a1;
	b = b1;
	c = c1;
	D = pow(b, 2) - 4 * a * c;
}
void eq2::get(double& a1, double& b1, double& c1)
{
	a1 = a;
	b1 = b;
	c1 = c;
}
double eq2::find_X()
{
	if (D < 0) 
	{ 
		//?
	}
	double x1, x2;
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);
	if (x1 >= x2) return x1;
	else return x2;
}
double eq2::find_Y(double x)
{
	return a * pow(x, 2) + b * x + c;
}

eq2 operator + (eq2 u1, eq2 u2)
{
	double a1, b1, c1;
	double a2, b2, c2;
	u1.get(a1, b1, c1);
	u2.get(a2, b2, c2);
	eq2 u3(a1+a2,b1+b2,c1+c2);
	return u3;
}