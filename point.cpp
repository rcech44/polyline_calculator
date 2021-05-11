#include "point.h"

point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int point::GetX()
{
	return this->x;
}

int point::GetY()
{
	return this->y;
}

void point::Delete()
{
	this->x = 0;
	this->y = 0;
}
