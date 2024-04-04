#include "Grayscale.h"

vector< vector<Pixel> > applyGrayscale(vector< vector<Pixel> > &image){

  for(int i = 0;i < image.size();i++){
    for (int j = 0; j < image[i].size(); j++){
      
      int tr, tg, tb;
      tr = 0.299 * image[i][j].r + 0.587 * image[i][j].g + 0.114 * image[i][j].b;
 
      if (tr > 255){
        image[i][j].r = 255;
      }
      else {
        image[i][j].r = tr;
        image[i][j].b=tr;
        image[i][j].g=tr;
      }

    }
  }

  return image;
}