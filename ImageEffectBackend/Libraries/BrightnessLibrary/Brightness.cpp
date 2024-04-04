#include "Brightness.h"

vector< vector<Pixel> > applyBrightness(vector< vector<Pixel> > &image, float amount) {
  
  if(amount == 100){
    return image;
  }

  else if(amount > 100){
    for(int i = 0;i < image.size();i++){
      for (int j = 0; j < image[i].size(); j++){
        if(image[i][j].r * (amount/100) < 255){
          image[i][j].r = image[i][j].r * (amount/100);
        }
        else{
          image[i][j].r = 255;
        }
        if(image[i][j].g * (amount/100) < 255){
          image[i][j].g = image[i][j].g * (amount/100);
        }
        else{
          image[i][j].g = 255;
        }
        if(image[i][j].b * (amount/100) < 255){
          image[i][j].b = image[i][j].b * (amount/100);
        }
        else{
          image[i][j].b = 255;
        }
      }
    }
  }

  else if(amount < 100){
    for(int i = 0;i < image.size();i++){
      for (int j = 0; j < image[i].size(); j++){
          image[i][j].r = image[i][j].r * (amount/100);
          image[i][j].g = image[i][j].g * (amount/100);
          image[i][j].b = image[i][j].b * (amount/100);
      }
    }
  }

  return image;
}