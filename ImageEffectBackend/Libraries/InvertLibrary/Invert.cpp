#include "Invert.h"

vector<vector<Pixel> > applyInvert(vector<vector<Pixel> > &image) {
    
    vector<vector<Pixel> > invertedImage = image;

    for (size_t i = 0; i < invertedImage.size(); ++i) {
        for (size_t j = 0; j < invertedImage[i].size(); ++j) {
            invertedImage[i][j].r = 255 - invertedImage[i][j].r;
            invertedImage[i][j].g = 255 - invertedImage[i][j].g;
            invertedImage[i][j].b = 255 - invertedImage[i][j].b;
        }
    }

    return invertedImage;
}