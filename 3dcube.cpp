#include "3dcube.h"
#include <string.h>
#include <stdlib.h>

const double pi2 = 2*M_PI;
const double divisions = 100;
const double theta_increase = pi2/divisions;


int main(){
   char** canvas = create_canvas();
   
   t_vertexs cube3d = {{-10.0, -10.0, -10.0}, {10.0, -10.0, -10.0}, {10.0, 10.0, -10.0}, {-10.0, 10.0, -10.0},
                        {-10.0, -10.0, 10.0}, {10.0, -10.0, 10.0}, {10.0, 10.0, 10.0}, {-10.0, 10.0, 10.0},};

   int index, y_canvas, x_canvas;
   t_point rot_p, projected_p;
   double theta;
   
   while(1){
      for(double theta=0;theta<pi2; theta+=theta_increase){
         reset_canvas(canvas);
         //puts("\x1b[1;1H");
         system("CLS");
         for(t_point point: cube3d){
             rotate(point, theta);
            
            while (point.size() != 2){
               reduce_project(point);
            }
               
            x_canvas = (int)round( res/2 + point[0] );
            y_canvas = (int)round( res/2 - point[1] );
            

            if (y_canvas < res && x_canvas < res){
                  canvas[y_canvas][x_canvas] = '*';
            }
            
            // cout << point[0] << " -> " << x_canvas << "; " << point[1]  << " -> " << y_canvas << " " << index<< endl;
            // cout << point[0] << " " << point[1] << endl;
            //system("CLS");
            //printf("\x1b[H");
          
         }
         print_canvas(canvas);
      }
   }
}