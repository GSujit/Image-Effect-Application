#include "Contrast.h"

vector<vector<Pixel> >  applyContrast(vector< vector<Pixel> > &image, float amount) {
    
     vector<vector<Pixel> > adjustedImage = image;

    for (int i = 0; i < image.size(); ++i) {
        for (int j = 0; j < image[i].size(); ++j) {

            adjustedImage[i][j].r = static_cast<int>((adjustedImage[i][j].r - 128) * (amount/100) + 128);
            adjustedImage[i][j].g = static_cast<int>((adjustedImage[i][j].g - 128) * (amount/100)  + 128);
            adjustedImage[i][j].b = static_cast<int>((adjustedImage[i][j].b - 128) * (amount/100) + 128);

            adjustedImage[i][j].r = min(255, max(0, adjustedImage[i][j].r));
            adjustedImage[i][j].g = min(255, max(0, adjustedImage[i][j].g));
            adjustedImage[i][j].b = min(255, max(0, adjustedImage[i][j].b));
        }
    }

    return adjustedImage;
}