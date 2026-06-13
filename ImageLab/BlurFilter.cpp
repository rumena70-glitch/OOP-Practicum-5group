#include "BlurFilter.h"

#include <vector>

void BlurFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    double constant = 1.0 / 9;
    double kernel[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            kernel[i][j] = constant;
        }
    }
    std::vector<Pixel> tempPixels(w * h);
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            tempPixels[y * w + x] = image.getPixel(x, y);
        }
    }
    for (size_t y = 1; y < h - 1; ++y) {
        for (size_t x = 1; x < w - 1; ++x) {
            double sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
            for (int ky = -1; ky <= 1; ++ky) {
                for (int kx = -1; kx <= 1; ++kx) {
                    Pixel neighbor = image.getPixel(x + kx, y + ky);
                    double weight = kernel[ky + 1][kx + 1];

                    sumR += neighbor.r * weight;
                    sumG += neighbor.g * weight;
                    sumB += neighbor.b * weight;
                }
            }
            tempPixels[y * w + x].r = (unsigned char)(sumR);
            tempPixels[y * w + x].g = (unsigned char)(sumG);
            tempPixels[y * w + x].b = (unsigned char)(sumB);
        }
    }
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            image.setPixel(x, y, tempPixels[y * w + x]);
        }
    }
}
