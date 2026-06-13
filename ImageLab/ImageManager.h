#ifndef IMAGELAB_IMAGEMANAGER_H
#define IMAGELAB_IMAGEMANAGER_H
#include <vector>

#include "Filter.h"
#include "Image.h"

struct ImagePipeline {
    std::string imageName;
    std::unique_ptr<Image> image;
    std::vector<std::unique_ptr<Filter>> filters;
};
class ImageManager {
    std::vector<ImagePipeline> pipelines;
    int findPipelineIndex(const std::string& name) const;
    std::unique_ptr<Filter> createFilterByName(const std::string& filterName);
public:
    void loadImage(const std::string& path);
    void addFilter(const std::string& imageName, const std::string& filterName);
    void removeFilter(const std::string& imageName, size_t filterIndex);
    void showFilters(const std::string& imageName) const;
    void showAllFilters() const;
    void run(const std::string& imageName);
    void runAll();
    void save(const std::string& imageName, const std::string& outputName = "");
};


#endif //IMAGELAB_IMAGEMANAGER_H
