#include "Sharpen.h"
#include<vector>

vector< vector<Pixel> > applySharpen(vector< vector<Pixel> > &image, float amount){
    
     vector< vector<Pixel> > sharpenedImage = image;
    
    vector<vector<float> > kernel = {
        {-1, -1, -1},
        {-1,  9, -1},
        {-1, -1, -1}
    };

    int kernelSize = kernel.size();
    int halfKernel = kernelSize / 2;

    int height = image.size();
    int width = image[0].size();

    for (int y = halfKernel; y < height - halfKernel; ++y) {
        for (int x = halfKernel; x < width - halfKernel; ++x) {
            int sumR = 0, sumG = 0, sumB = 0;

            for (int i = -halfKernel; i <= halfKernel; ++i) {
                for (int j = -halfKernel; j <= halfKernel; ++j) {
                    int pixelX = x + j;
                    int pixelY = y + i;

                    sumR += image[pixelY][pixelX].r * kernel[i + halfKernel][j + halfKernel];
                    sumG += image[pixelY][pixelX].g * kernel[i + halfKernel][j + halfKernel];
                    sumB += image[pixelY][pixelX].b * kernel[i + halfKernel][j + halfKernel];
                }
            }

            sharpenedImage[y][x].r = static_cast<int>(image[y][x].r + (amount/100) * (sumR - image[y][x].r));
            sharpenedImage[y][x].g = static_cast<int>(image[y][x].g + (amount/100) * (sumG - image[y][x].g));
            sharpenedImage[y][x].b = static_cast<int>(image[y][x].b + (amount/100) * (sumB - image[y][x].b));

            sharpenedImage[y][x].r = std::min(255, std::max(0, sharpenedImage[y][x].r));
            sharpenedImage[y][x].g = std::min(255, std::max(0, sharpenedImage[y][x].g));
            sharpenedImage[y][x].b = std::min(255, std::max(0, sharpenedImage[y][x].b));
        }
    }

    return sharpenedImage;

}