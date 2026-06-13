#ifndef IMAGELAB_PPMIMAGE_H
#define IMAGELAB_PPMIMAGE_H
#include <vector>
#include "Image.h"

class PPMImage : public Image {
    int maxValue;
    std::vector<Pixel> pixels;
public:
    void load(const std::string& path) override;
    void save(const std::string& path) override;
    Pixel getPixel(size_t x, size_t y) const override;
    void setPixel(size_t x, size_t y, const Pixel& p) override;
};


#endif //IMAGELAB_PPMIMAGE_H
