#include <cmath>
#include "object.h"

class sensor
{
private:
	float pos_x;
	float pos_y;
	float radius;
	float gip(float x, float y)
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
public:
	sensor()
	{
		pos_x = 0;
		pos_y = 0;
		radius = 10;
	}
	sensor(float x, float y, float r)
	{
		pos_x = x;
		pos_y = y;
		radius = r;
	}
	void set(float x, float y, float r);
	bool cheak(object* D, int size);
	int count(object* D, int size);
};
