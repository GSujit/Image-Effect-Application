#ifndef HUE_SATURATION_H
#define HUE_SATURATION_H
#include<vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "../Pixel.h"

using namespace std;

vector< vector<Pixel> > applyHueSaturation(vector< vector<Pixel> > &image, float saturationValue, float hueValue);

#endif