#ifndef IMAGELAB_THRESHOLDFILTER_H
#define IMAGELAB_THRESHOLDFILTER_H
#include "Filter.h"


class ThresholdFilter : public Filter {
    int threshold;
public:
    ThresholdFilter(int thresh = 128);
    void execute(Image &image) override;
    std::string getName() const override;
};


#endif //IMAGELAB_THRESHOLDFILTER_H
