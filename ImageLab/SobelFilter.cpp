#include "SobelFilter.h"

#include <vector>

SobelFilter::SobelFilter(int thresh) : threshold(thresh) {}

void SobelFilter::execute(Image &image) {
    size_t w = image.getWidth();
    size_t h = image.getHeight();
    int Kx[3][3] = {
        { -1, 0, 1 },
        { -2, 0, 2 },
        { -1, 0, 1 }
    };
    int Ky[3][3] = {
        { -1, 2, -1 },
        { 0, 0, 0 },
        { 1, 2, 1 }
    };
    std::vector<double> magnitudes(w * h, 0.0);
    for (size_t y = 1; y < h - 1; ++y) {
        for (size_t x = 1; x < w - 1; ++x) {

            double gx = 0.0;
            double gy = 0.0;

            for (int ky = -1; ky <= 1; ++ky) {
                for (int kx = -1; kx <= 1; ++kx) {
                    auto [r, g, b] = image.getPixel(x + kx, y + ky);

                    double gray = 0.299 * r + 0.587 * g + 0.114 * b;

                    gx += gray * Kx[ky + 1][kx + 1];
                    gy += gray * Ky[ky + 1][kx + 1];
                }
            }

            magnitudes[y * w + x] = std::sqrt(gx * gx + gy * gy);
        }
    }

    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            double val = magnitudes[y * w + x];

            if (val > 255.0) {
                val = 255.0;
            }

            Pixel p;
            if (threshold == -1) {
                auto grayVal = (unsigned char) val;
                p = { grayVal, grayVal, grayVal };
            }
            else {
                if (val >= threshold) {
                    p = { 0, 0, 0 };
                }
                else {
                    p = { 255, 255, 255 };
                }
            }
            image.setPixel(x, y, p);
        }
    }
}

std::string SobelFilter::getName() const {
    if (threshold == -1) {
        return "sobel (grayscale)";
    }
    return "sobel (binary, " + std::to_string(threshold) + ")";
}
