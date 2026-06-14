#ifndef IMAGELAB_NEGATIVEFILTER_H
#define IMAGELAB_NEGATIVEFILTER_H
#include "Filter.h"

class NegativeFilter : public Filter {
public:
    void execute(Image &image) override;
    std::string getName() const override;
};


#endif //IMAGELAB_NEGATIVEFILTER_H
