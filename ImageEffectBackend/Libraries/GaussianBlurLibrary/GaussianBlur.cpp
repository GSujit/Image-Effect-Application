#include "GaussianBlur.h"

vector< vector<Pixel> > applyGaussianBlur(vector< vector<Pixel> >& image, float radius) {

    int height = image.size();
    int width = image[0].size();
    int r = static_cast<int>(radius);
    double sigma = 10 + static_cast<int>(radius/10);

    int kernelSize = 2 * r + 1;
    vector< vector<double> > kernel(kernelSize, vector<double>(kernelSize, 0.0));

    double sum = 0.0;
    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            kernel[i][j] = std::exp(-(i * i + j * j) / (2.0 * sigma * sigma)) / (2.0 * M_PI * sigma * sigma);
            sum += kernel[i][j];
        }
    }

    for (int i = 0; i < kernelSize; ++i) {
        for (int j = 0; j < kernelSize; ++j) {
            kernel[i][j] /= sum;
        }
    }

    vector< vector<Pixel> > output(height, vector<Pixel>(width));
    int kernelRadius = kernelSize / 2;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            double sumR = 0.0, sumG = 0.0, sumB = 0.0;

            for (int pixelX = 0; pixelX < kernelSize; ++pixelX) {
                int x = i - kernelRadius + pixelX;
                x = max(0, min(height - 1, x));

                for (int pixelY = 0; pixelY < kernelSize; ++pixelY) {
                    int y = j - kernelRadius + pixelY;
                    y = max(0, min(width - 1, y));

                    sumR += image[x][y].r * kernel[pixelX][pixelY];
                    sumG += image[x][y].g * kernel[pixelX][pixelY];
                    sumB += image[x][y].b * kernel[pixelX][pixelY];
                }
            }

            output[i][j].r = static_cast<int>(min(255.0, max(0.0, sumR)));
            output[i][j].g = static_cast<int>(min(255.0, max(0.0, sumG)));
            output[i][j].b = static_cast<int>(min(255.0, max(0.0, sumB)));
        }
    }

    return output; 
}