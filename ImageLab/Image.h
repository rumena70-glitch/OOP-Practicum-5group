#ifndef IMAGELAB_IMAGE_H
#define IMAGELAB_IMAGE_H
#include <iostream>

struct Pixel {
    unsigned char r, g, b;
};

class Image {
protected:
    size_t width;
    size_t height;
    std::string filePath;
public:
    virtual void load(const std::string& path) = 0;
    virtual void save(const std::string& path) = 0;
    virtual ~Image() = default;

    size_t getWidth() const;
    size_t getHeight() const;

    virtual Pixel getPixel(size_t x, size_t y) const = 0;
    virtual void setPixel(size_t x, size_t y, const Pixel& p) = 0;
};


#endif //IMAGELAB_IMAGE_H
