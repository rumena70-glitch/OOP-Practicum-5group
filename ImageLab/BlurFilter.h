#ifndef IMAGELAB_BLURFILTER_H
#define IMAGELAB_BLURFILTER_H
#include "Filter.h"


class BlurFilter : public Filter {
public:
    void execute(Image &image) override;
    std::string getName() const override;
};


#endif //IMAGELAB_BLURFILTER_H
