#ifndef SHARPEN_H
#define SHARPEN_H
#include<vector>
#include <cmath>
#include "../Pixel.h"

using namespace std;

vector< vector<Pixel> > applySharpen(vector< vector<Pixel> > &image, float radius);

#endif