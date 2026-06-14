#ifndef IMAGELAB_SOBELFILTER_H
#define IMAGELAB_SOBELFILTER_H
#include "Filter.h"


class SobelFilter : public Filter {
    int threshold;
public:
    SobelFilter(int thresh = -1);

    void execute(Image &image) override;
    std::string getName() const override;
};


#endif //IMAGELAB_SOBELFILTER_H
