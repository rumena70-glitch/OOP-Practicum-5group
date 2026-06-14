#include "ThresholdFilter.h"

ThresholdFilter::ThresholdFilter(int thresh) : threshold(thresh) {}

void ThresholdFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            Pixel p = image.getPixel(x, y);
            double gray = 0.299 * p.r + 0.587 * p.g + 0.114 * p.b;
            if (gray >= threshold) {
                p = { 255, 255, 255 };
            }
            else {
                p = { 0, 0, 0 };
            }
            image.setPixel(x, y, p);
        }
    }
}

std::string ThresholdFilter::getName() const {
    return "threshold (value: " + std::to_string(threshold) + ")";
}
