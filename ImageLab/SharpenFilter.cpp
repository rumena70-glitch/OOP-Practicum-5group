#include "SharpenFilter.h"

#include <vector>

void SharpenFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    double kernel[3][3] = {
        { 0, -1, 0 },
        { -1, 5, -1 },
        { 0, -1, 0 }
    };
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
            if (sumR < 0) {
                sumR = 0;
            }
            if (sumR > 255) {
                sumR = 255;
            }
            if (sumG < 0) {
                sumG = 0;
            }
            if (sumG > 255) {
                sumG = 255;
            }
            if (sumB < 0) {
                sumB = 0;
            }
            if (sumB > 255) {
                sumB = 255;
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

std::string SharpenFilter::getName() const {
    return "Sharpen";
}
