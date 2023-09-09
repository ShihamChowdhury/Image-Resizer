// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cassert>
#include "Matrix.h"
#include "processing.h"
#include "Image.h"

using namespace std;

int main(int argc, char *argv[]) {

   if(argc != 4 && argc != 5){
     cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
          << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1; 
   }

   ifstream input;
   input.open(argv[1]);
   if(!input.is_open()){
       cout << "Error opening file: " << argv[1] << endl;
       return 1;
   }

   Image *img = new Image;
   Image_init(img,input);
   input.close();
   if(argc == 4) {
    if(0 < atoi(argv[3]) && atoi(argv[3]) <= Image_width(img)){
      seam_carve_width(img, atoi(argv[3]));
     }
    else{
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        delete img;
        return 1;
    }
   }

   else if(argc == 5) {
    if(0 < atoi(argv[3]) && atoi(argv[3]) <= Image_width(img) 
    && 0 < atoi(argv[4]) && atoi(argv[4]) <= Image_height(img)){
      seam_carve(img, atoi(argv[3]), atoi(argv[4]));
     }
    else{
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        delete img;
        return 1;
    }
   }

   ofstream output;
   output.open(argv[2]);
   if(!output.is_open()){
       cout << "Error opening file: " << argv[2] << endl;
       delete img;
       return 1;
   }
   Image_print(img, output);
   delete img;
   output.close();
   return 0;
}