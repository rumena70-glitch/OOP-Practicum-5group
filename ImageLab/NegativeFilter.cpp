#include "NegativeFilter.h"

void NegativeFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            Pixel p = image.getPixel(x, y);
            p.r = 255 - p.r;
            p.g = 255 - p.g;
            p.b = 255 - p.b;
            image.setPixel(x, y, p);
        }
    }
}

std::string NegativeFilter::getName() const {
    return "Negative";
}
