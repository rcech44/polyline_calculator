#include <iostream>
#include <string.h>
#include "polyline.h"
#include "point.h"
#include <time.h>
#include <stdlib.h>
#include "Colours.h"
#include <windows.h>

using namespace std;

void generatePoints(polyline* line, int count);
int randomIntGeneratorNP(int max);  // od -max po max (negative positive)
int randomIntGenerator(int max);    // od 0 po max

int main()
{
    srand(time(NULL));

    // nastaveni velikosti konzole
    SMALL_RECT windowSize = { 0 , 0 , 101 , 52 }; // change the values
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

    // zacatek programu
    int maxPoints = 1000000;        // maximalni pocet bodu v krivce
    polyline* krivka = new polyline(maxPoints);
    generatePoints(krivka, 50);
    krivka->DeletePoint(15);
    krivka->DeletePointFromTop();
    krivka->RenderGraph();
    krivka->Report();
    printf("Polyline length: %f\n", krivka->Length());

    delete krivka;
}

int randomIntGeneratorNP(int max)
{
    return (rand() % (max + max + 1) + (-max));
}

int randomIntGenerator(int max)
{
    return (rand() % max + 1);
}

void generatePoints(polyline* line, int count)
{
    for (int i = 0; i < count; i++)
    {
        line->AddPoint(randomIntGeneratorNP(49), randomIntGeneratorNP(20));
    }
}