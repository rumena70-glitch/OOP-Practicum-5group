#ifndef IMAGELAB_FILTER_H
#define IMAGELAB_FILTER_H
#include "Image.h"

class Filter {
public:
    virtual void execute(Image& image) = 0;
    virtual ~Filter() = default;
};

#endif //IMAGELAB_FILTER_H
