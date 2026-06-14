#include "ImageManager.h"

#include "BlurFilter.h"
#include "NegativeFilter.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include "SharpenFilter.h"


int ImageManager::findPipelineIndex(const std::string &name) const {
    for (size_t i = 0; i < pipelines.size(); ++i) {
        if (pipelines[i].imageName == name) {
            return (int) i;
        }
    }
    return -1;
}

std::unique_ptr<Filter> ImageManager::createFilterByName(const std::string &filterName) {
    if (filterName == "negative") {
        return std::make_unique<NegativeFilter>();
    }
    if (filterName == "blur") {
        return std::make_unique<BlurFilter>();
    }
    if (filterName == "sharpen") {
        return std::make_unique<SharpenFilter>();
    }
    return nullptr;
}

void ImageManager::loadImage(const std::string &path) {
    std::string name = path.substr(path.find_last_of("/\\") + 1);
    if (findPipelineIndex(name) != -1) {
        std::cout << "Image " << name << " is already loaded." << std::endl;
        return;
    }
    std::unique_ptr<Image> newImage = nullptr;
    if (path.size() >= 4) {
        std::string ext = path.substr(path.size() - 4);
        if (ext == ".ppm") {
            newImage = std::make_unique<PPMImage>();
        }
        else if (ext == ".pgm") {
            newImage = std::make_unique<PGMImage>();
        }
        else if (ext == ".pbm") {
            newImage = std::make_unique<PBMImage>();
        }
    }
    if (!newImage) {
        std::cout << "Error! Unsupported file extension." << std::endl;
        return;
    }
    try {
        newImage -> load(path);
        std::cout << "Loaded: " << name << " (" << newImage->getWidth() << "x" << newImage->getHeight() << ")" <<
                std::endl;
        ImagePipeline pipe;
        pipe.imageName = name;
        pipe.image = std::move(newImage);
        pipelines.push_back(std::move(pipe));
    }
    catch (const std::exception& e) {
        std::cout << "Error loading file: " << e.what() << std::endl;
    }
}

void ImageManager::addFilter(const std::string &imageName, const std::string &filterName) {
    int idx = findPipelineIndex(imageName);
    if (idx == -1) {
        std::cout << "Error! Image '" << imageName << "' not loaded." << std::endl;
        return;
    }
    auto f = createFilterByName(filterName);
    if (!f) {
        std::cout << "Error! Unknown filter '" << filterName << "'." << std::endl;
        return;
    }
    pipelines[idx].filters.push_back(std::move(f));
    std::cout << "Added filter '" << filterName << "' to '" << imageName << "' (index " << pipelines[idx].filters.size() - 1 << ")" << std::endl;
}

void ImageManager::removeFilter(const std::string &imageName, size_t filterIndex) {
}

void ImageManager::showFilters(const std::string &imageName) const {
}

void ImageManager::showAllFilters() const {
}

void ImageManager::run(const std::string &imageName) {
    int idx = findPipelineIndex(imageName);
    if (idx == -1) {
        std::cout << "Error: Image '" << imageName << "' not loaded." << std::endl;
        return;
    }
    auto& pipe = pipelines[idx];
    if (pipe.filters.empty()) {
        std::cout << "No filters to apply for " << imageName << "." << std::endl;
        return;
    }
    std::cout << "Running pipeline for " << imageName << "..." << std::endl;
    for (const auto& f : pipe.filters) {
        f -> execute(*pipe.image);
    }
    std::string outName = "processed_" + pipe.imageName;
    try {
        pipe.image -> save(outName);
        std::cout << "Successfully saved result to " << outName << std::endl;
        pipe.filters.clear();
    }
    catch (const std::exception& e) {
        std::cout << "Error saving result: " << e.what() << std::endl;
    }
}

void ImageManager::runAll() {
    std::cout << "Running pipeline for all " << pipelines.size() << " image(s)..." << std::endl;
    for (const auto& pipe : pipelines) {
        run(pipe.imageName);
    }
}

void ImageManager::save(const std::string &imageName, const std::string &outputName) {
}
