#include "Rotation.h"

vector<vector<Pixel> > applyRotation(vector<vector<Pixel> > &image, int value) { 

    if(value == 0)
        return image;

    vector<vector<Pixel> > rotated_image;
        
    for(int i=0;i<image[0].size();i++)
    {
        vector<Pixel>row ;
        for(int j=image.size()-1;j>=0;j--)
        {
            row.push_back(image[j][i]);
        }
        rotated_image.push_back(row);
    }
    
    if (value == 1)
        return rotated_image;

    vector<vector<Pixel> > rotated_image2;
        
    for(int i=0;i<rotated_image[0].size();i++)
    {
        vector<Pixel>row ;
        for(int j=rotated_image.size()-1;j>=0;j--)
        {
            row.push_back(rotated_image[j][i]);
        }
        rotated_image2.push_back(row);
    }

    if(value == 2)
        return rotated_image2;

    vector<vector<Pixel> > rotated_image3;
        
    for(int i=0;i<rotated_image2[0].size();i++)
    {
        vector<Pixel>row ;
        for(int j=rotated_image2.size()-1;j>=0;j--)
        {
            row.push_back(rotated_image2[j][i]);
        }
        rotated_image3.push_back(row);
    }

    if(value == 3)
        return rotated_image3;
        
}