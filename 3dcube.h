#pragma once
#include <vector>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


#define MAGNIFICATION 20
#define DISTANCE 30
#define res 50
#define PERSPECTIVE false

using namespace std;

typedef vector<double> t_point;
typedef vector<t_point> t_vertexs;



void perpspective_projection(t_point& );
void rotate(t_point&, double);
void reset_canvas(char**);
void print_canvas(char**);
char** create_canvas();
