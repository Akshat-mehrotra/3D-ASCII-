#include "3dcube.h"


void perpspective_projection(t_point& point){
    float last_coord = point.back();
    point.pop_back();

    for(int i=0; i<point.size(); i++){
        point[i] = (point[i]*(MAGNIFICATION)/((last_coord + DISTANCE)));
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
    // x rotation
    //point[1] = point[1] * cos(theta) - point[2] * sin(theta);
    //point[2] = point[1] * sin(theta) + point[2] * cos(theta);

    // y rotation
    //point[0] = point[0] * cos(theta) + point[2] * sin(theta);
    //point[2] = -1 * point[0] * sin(theta) + point[2] * cos(theta);

    // z rotation
    point[0] = point[0] * cos(theta) - point[1] * sin(theta);
    point[1] = point[1] * cos(theta) + point[2] * sin(theta);

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
