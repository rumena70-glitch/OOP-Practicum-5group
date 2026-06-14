#ifndef IMAGELAB_NORMALIZEFILTER_H
#define IMAGELAB_NORMALIZEFILTER_H
#include "Filter.h"


class NormalizeFilter : public Filter {
public:
    void execute(Image &image) override;
    std::string getName() const override;
};


#endif //IMAGELAB_NORMALIZEFILTER_H
