#include "Flip.h"

vector<vector<Pixel> > applyFlip(vector<vector<Pixel> > &image,int horizontalFlipValue = 0, int verticalFlipValue = 0) {

    vector<vector<Pixel> > flippedImage = image;

    if (horizontalFlipValue == 1) {
        for (vector<vector<Pixel> >::iterator it = flippedImage.begin(); it != flippedImage.end(); ++it) {
            reverse(it->begin(), it->end());
        }
    }

    if(verticalFlipValue==1){
      reverse(flippedImage.begin(), flippedImage.end());
    }

    return flippedImage;
}