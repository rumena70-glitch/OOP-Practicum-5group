#ifndef IMAGELAB_PBMIMAGE_H
#define IMAGELAB_PBMIMAGE_H
#include <vector>

#include "Image.h"


class PBMImage : public Image {
    std::vector<bool> pixels;
public:
    void load(const std::string& path) override;
    void save(const std::string& path) override;

    Pixel getPixel(size_t x, size_t y) const override;
    void setPixel(size_t x, size_t y, const Pixel& p) override;
};


#endif //IMAGELAB_PBMIMAGE_H
