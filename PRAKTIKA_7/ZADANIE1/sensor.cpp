#include "sensor.h"

bool sensor::cheak(object* D, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (gip((D[i]).get_x(), (D[i]).get_y()) <= radius) return true;
	}
	return false;
}
int sensor::count(object* D, int size)
{
	int tr = 0;
	for (int i = 0; i < size; i++)
	{
		if (gip((D[i]).get_x(), (D[i]).get_y()) <= radius) tr += 1;
	}
	return tr;
}
void sensor::set(float x, float y, float r)
{
	pos_x = x;
	pos_y = y;
	radius = r;
}