#ifndef IMAGELAB_PGMIMAGE_H
#define IMAGELAB_PGMIMAGE_H
#include <vector>

#include "Image.h"


class PGMImage : public Image {
    unsigned maxValue = 255;
    std::vector<unsigned char> pixels;
public:
    void load(const std::string& path) override;
    void save(const std::string& path) override;

    Pixel getPixel(size_t x, size_t y) const override;
    void setPixel(size_t x, size_t y, const Pixel& p) override;
};


#endif //IMAGELAB_PGMIMAGE_H
