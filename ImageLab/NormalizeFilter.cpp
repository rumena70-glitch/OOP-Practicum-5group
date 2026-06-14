#include "NormalizeFilter.h"

void NormalizeFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    if (w == 0 || h == 0) {
        return;
    }
    unsigned char minR = 255, minG = 255, minB = 255;
    unsigned char maxR = 0, maxG = 0, maxB = 0;
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            Pixel p = image.getPixel(x, y);

            if (p.r < minR) {
                minR = p.r;
            }
            if (p.r > maxR) {
                maxR = p.r;
            }

            if (p.g < minG) {
                minG = p.g;
            }
            if (p.g > maxG) {
                maxG = p.g;
            }

            if (p.b < minB) {
                minB = p.b;
            }
            if (p.b > maxB) {
                maxB = p.b;
            }
        }
    }
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            Pixel p = image.getPixel(x, y);

            if (maxR != minR) {
                p.r = (unsigned char) ((p.r - minR) / (double) (maxR - minR) * 255.0f);
            }
            if (maxG != minG) {
                p.g = (unsigned char) ((p.g - minG) / (double) (maxG - minG) * 255.0f);
            }
            if (maxB != minB) {
                p.b = (unsigned char) (((p.b - minB) / (double) (maxB - minB)) * 255.0f);
            }

            image.setPixel(x, y, p);
        }
    }
}

std::string NormalizeFilter::getName() const {
    return "normalize";
}
