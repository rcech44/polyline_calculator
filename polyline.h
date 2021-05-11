#pragma once

#include "point.h"

using namespace std;

class polyline
{
private:
	point** points;
	int numOfPoints;
	int maxPoints;
public:
	polyline(int maxPoints);
	~polyline();
	int GetMaxPoints();
	void AddPoint(int x, int y);
	void DeletePointFromTop();
	void DeletePoint(int number);
	void Report();
	double Length();
	void RenderGraph();
};