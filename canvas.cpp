#include "3dcube.h"


void reduce_project(t_point& point){
    float last_coord = point.back();
    point.pop_back();

    for(int i=0; i<point.size(); i++){
        point[i] = (point[i]*(PLANE)/(last_coord + DISTANCE));
    }
}

char** create_canvas() {
    char** canvas = (char**)malloc(sizeof(char*) * res);
    char* row;
    for (int a = 0; a < res; a++) {
        row = (char*)malloc(sizeof(char) * res);
        for (int b = 0; b < res; b++) {
            row[b] = ' ';
        }
        canvas[a] = row;
    }
    return canvas;
}

void rotate(t_point& point, double theta){
    point[1] = point[1]*cos(theta) + point[2]*sin(theta);  
}

void reset_canvas(char** canvas){
   for(int i=0; i<res; i++){
      for(int j=0; j<res; j++){
         canvas[i][j] = ' ';
      }
   }
}

void print_canvas(char** canvas){
    for(int i=0; i<res; i++){
      for(int j=0; j<res; j++){
          putc(canvas[i][j], stdout);
      }
      putc('\n', stdout);
   }
}
