#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H
#include<vector>
#include <cmath>
#include "../Pixel.h"

using namespace std;

vector< vector<Pixel> > applyGaussianBlur(vector< vector<Pixel> > &image, float radius);

#endif