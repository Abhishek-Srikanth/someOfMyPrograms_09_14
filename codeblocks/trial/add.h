using namespace std;

#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

float sum (float x, float y);
float diff (float a, float b);

#endif // ADD_H_INCLUDED

#include <iostream>

float sum (float x, float y)
{
    float z = x + y;
    return z;
}

float diff (float a, float b)
{
    float c = b - a;
    if (c < 0)
    c *= -1;
    return c;
}
