#pragma once

using namespace std;

class point
{
private:
	int x;
	int y;
public:
	point(int x, int y);
	int GetX();
	int GetY();
	void Delete();
};

