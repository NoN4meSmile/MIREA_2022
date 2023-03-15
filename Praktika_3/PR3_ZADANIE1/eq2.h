#include <cmath>
#include <iostream>

using namespace std;

class eq2
{
private:
	double a, b, c;
	double D;
public:
	eq2(){
		a = 0;
		b = 0;
		c = 0;
		D = 0;
	}
	eq2(double a1, double b1, double c1)
	{
		a = a1;
		b = b1;
		c = c1;
		D = pow(b, 2) - 4 * a * c;
	}
	void set(double a1, double b1, double c1);
	void get(double& a1, double& b1, double& c1);
	double find_X();
	double find_Y(double x);
};

eq2 operator + (eq2 u1, eq2 u2);

