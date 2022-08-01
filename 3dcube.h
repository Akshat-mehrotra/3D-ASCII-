#pragma once
#include <vector>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


#define PLANE 10
#define DISTANCE 40
#define res 40


using namespace std;

typedef vector<double> t_point;
typedef vector<t_point> t_vertexs;

void reduce_project(t_point& );
void rotate(t_point&, double);
void reset_canvas(char**);
void print_canvas(char**);
char** create_canvas();