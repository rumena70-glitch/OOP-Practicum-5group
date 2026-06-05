#ifndef IMAGELAB_IMAGE_H
#define IMAGELAB_IMAGE_H
#include <iostream>

class Image {
protected:
    size_t width;
    size_t height;
public:
    virtual void load(...) = 0;
    virtual void save(...) = 0;
    virtual ~Image() = default;
};


#endif //IMAGELAB_IMAGE_H
