#ifndef IMAGELAB_SHARPENFILTER_H
#define IMAGELAB_SHARPENFILTER_H
#include "Filter.h"


class SharpenFilter : public Filter {
public:
    void execute(Image &image) override;
};


#endif //IMAGELAB_SHARPENFILTER_H
