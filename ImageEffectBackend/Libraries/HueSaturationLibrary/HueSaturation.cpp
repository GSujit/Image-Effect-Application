#include "HueSaturation.h"

void rgbToHsv(int r, int g, int b, double& h, double& s, double& v) {
    double rr = r / 255.0;
    double gg = g / 255.0;
    double bb = b / 255.0;

    double cmax =  max(max(rr, gg), bb);
    double cmin = min(min(rr, gg), bb);
    double delta = cmax - cmin;

    h = 0.0;
    if (delta != 0.0) {
        if (cmax == rr) {
            h = 60.0 * fmod((gg - bb) / delta, 6.0);
        } else if (cmax == gg) {
            h = 60.0 * ((bb - rr) / delta + 2.0);
        } else if (cmax == bb) {
            h = 60.0 * ((rr - gg) / delta + 4.0);
        }
    }

    s = (cmax != 0.0) ? (delta / cmax) : 0.0;

    v = cmax;
}

void hsvToRgb(double h, double s, double v, int& r, int& g, int& b) {
    double c = v * s;
    double x = c * (1.0 - abs(fmod(h / 60.0, 2.0) - 1.0));
    double m = v - c;

    double rr, gg, bb;
    if (h >= 0.0 && h < 60.0) {
        rr = c;
        gg = x;
        bb = 0.0;
    } else if (h >= 60.0 && h < 120.0) {
        rr = x;
        gg = c;
        bb = 0.0;
    } else if (h >= 120.0 && h < 180.0) {
        rr = 0.0;
        gg = c;
        bb = x;
    } else if (h >= 180.0 && h < 240.0) {
        rr = 0.0;
        gg = x;
        bb = c;
    } else if (h >= 240.0 && h < 300.0) {
        rr = x;
        gg = 0.0;
        bb = c;
    } else {
        rr = c;
        gg = 0.0;
        bb = x;
    }

    r = static_cast<int>((rr + m) * 255.0);
    g = static_cast<int>((gg + m) * 255.0);
    b = static_cast<int>((bb + m) * 255.0);
}


vector< vector<Pixel> > applyHueSaturation(vector< vector<Pixel> > &image, float saturationValue, float hueValue) {

    for(int i = 0;i < image.size();i++){
      for (int j = 0; j < image[i].size(); j++){
           double h, s, v;

           rgbToHsv(image[i][j].r, image[i][j].g, image[i][j].b, h, s, v);

           int r,g,b;

            hsvToRgb(hueValue, saturationValue/100, v, r, g, b);

            image[i][j].r=r;
            image[i][j].g=g;
            image[i][j].b=b;
        }
    } 

    return image; 

}
