#ifndef FLIP_H
#define FLIP_H
#include <vector>
#include <algorithm>
#include "../Pixel.h"

using namespace std;

vector<vector<Pixel> > applyFlip(vector<vector<Pixel> > &image,int horizontalFlipValue, int verticalFlipValue);

#endif