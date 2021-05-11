#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include "polyline.h"
#include "point.h"
#include "Colours.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define clrscr() system("@cls||clear")

using namespace std;

polyline::polyline(int maxPoints)
{
	this->maxPoints = maxPoints;
	this->numOfPoints = 0;
	this->points = new point * [maxPoints];
}

polyline::~polyline()
{
	delete[] this->points;
}

int polyline::GetMaxPoints()
{
	return this->maxPoints;
}

void polyline::AddPoint(int x, int y)
{
	point* tempPoint = new point(x, y);
	this->points[numOfPoints] = tempPoint;
	numOfPoints++;
}

void polyline::DeletePointFromTop()
{
	if (this->numOfPoints == 0) printf("No points to delete.\n");
	else
	{
		this->points[numOfPoints - 1]->Delete();
		this->numOfPoints--;
	}
}

void polyline::DeletePoint(int number)
{
	if (number > this->numOfPoints)
	{
		printf("# Deleting %d. point: ", number);
		cout << RED << "Failed." << CRESET << endl << endl;
	}
	else
	{
		printf("# Deleting %d. point: ", number);
		int x = this->points[number - 1]->GetX();
		int y = this->points[number - 1]->GetY();
		this->points[number - 1]->Delete();
		cout << GREEN << "Successful." << CRESET << endl << endl;
		for (int i = number - 1; i < this->numOfPoints - 1; i++)
		{
			this->points[i] = this->points[i + 1];
		}
		this->numOfPoints--;
	}
}

void polyline::Report()
{
	printf("Polyline details:\n\nnumber\t\tX\tY\n");
	printf("-----------------------------------\n");
	for (int i = 0; i < this->numOfPoints; i++)
	{
		printf(" %d\t =\t%d,\t%d\n", i+1, this->points[i]->GetX(), this->points[i]->GetY());
	}
	printf("-----------------------------------\n");
	printf("Number of points: %d\n", this->numOfPoints);
}

double polyline::Length()
{
	double length = 0;
	for (int i = 0; i < (this->numOfPoints - 1); i++)
	{
		// (abs x1 - x2)2 + (abs y1 - y2)2 = vysledek a ten odmocnim
		double vysledek = 0;
		int x1 = this->points[i]->GetX();
		int y1 = this->points[i]->GetY();
		int x2 = this->points[i+1]->GetX();
		int y2 = this->points[i+1]->GetY();
		length += sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	}
	return length;
}

void polyline::RenderGraph()
{
	// vymazani plochy a render os
	clrscr();
	for (int i = 1; i < 101; i++)
	{
		gotoxy(i, 45);
		printf("#");
		gotoxy(i, 22);
		printf("-");
	}
	for (int i = 1; i < 46; i++)
	{
		gotoxy(51, i);
		printf("|");
	}
	gotoxy(51,22);
	printf("+");
	gotoxy(1,46);
	// konec renderu os

	// vypsani bodu

	if (this->numOfPoints == 0)
	{
		printf("No points to render. Quiting.\n");
		return;
	}

	for (int i = 0; i < this->numOfPoints; i++)
	{
		cout << CYAN;
		gotoxy(1, 47);
		printf("\t# Rendering %d. point.              \n\t# X = %d, Y = %d             ", i+1, this->points[i]->GetX(), this->points[i]->GetY());
		cout << CRESET;

		// vypocet pozice na grafu
		int x = this->points[i]->GetX() + 51;
		int y = 45 - (this->points[i]->GetY() + 23);
		gotoxy(x, y);
		cout << YELLOW << "o" << CRESET;

		gotoxy(98, 24);
		printf("x");
		gotoxy(54, 2);
		printf("y");
		gotoxy(0,0);
		Sleep(200);
	}

	// konec vypsani bodu
	gotoxy(1, 48);
	printf("\n\n");
}
