#include "Sepia.h"

vector< vector<Pixel> > applySepia(vector< vector<Pixel> > &image) {

  for(int i = 0;i < image.size();i++){
    for (int j = 0; j < image[i].size(); j++){
      
      int tr, tg, tb;
      tr = 0.393 * image[i][j].r + 0.769 * image[i][j].g + 0.189 * image[i][j].b;
      tg = 0.349 * image[i][j].r + 0.686 * image[i][j].g + 0.168 * image[i][j].b;
      tb = 0.272 * image[i][j].r + 0.534 * image[i][j].g + 0.131 * image[i][j].b;

      if (tr > 255){
        image[i][j].r = 255;
      }
      else {
        image[i][j].r = tr;
      }
      if (tg > 255){
        image[i][j].g = 255;
      }  
      else {
        image[i][j].g = tg;
      }
      if(tb > 255){
        image[i][j].b = 255; 
      }
      else {
        image[i][j].b = tb;
      }
    }
  }

  return image;
}