#include "ImageManager.h"

#include "BlurFilter.h"
#include "NegativeFilter.h"
#include "NormalizeFilter.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include "SharpenFilter.h"
#include "SobelFilter.h"
#include "ThresholdFilter.h"


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
    if (filterName.substr(0, 5) == "sobel") {
        size_t colonPos = filterName.find(':');
        if (colonPos != std::string::npos) {
            try {
                int thresh = std::stoi(filterName.substr(colonPos + 1));
                return std::make_unique<SobelFilter>(thresh);
            }
            catch (const std::exception& e) {
                std::cout << "Invalid threshold format. Using grayscale mode instead." << std::endl;
            }
        }
        return std::make_unique<SobelFilter>();
    }
    if (filterName == "normalize") {
        return std::make_unique<NormalizeFilter>();
    }
    if (filterName.substr(0, 9) == "threshold") {
        size_t colonPos = filterName.find(':');
        if (colonPos != std::string::npos) {
            try {
                int thresh = std::stoi(filterName.substr(colonPos + 1));
                return std::make_unique<ThresholdFilter>(thresh);
            }
            catch (...) {
                std::cout << "Invalid threshold format. Using default value (128)." << std::endl;
            }
        }
        return std::make_unique<ThresholdFilter>();
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
    int idx = findPipelineIndex(imageName);
    if (idx == -1) {
        std::cout << "Error! Image '" << imageName << "' not loaded." << std::endl;
        return;
    }
    auto& pipe = pipelines[idx];
    if (filterIndex >= pipe.filters.size()) {
        std::cout << "Error! Invalid filter index!" << filterIndex << std::endl;
        return;
    }
    std::string filterName = pipe.filters[filterIndex]->getName();
    pipe.filters.erase(pipe.filters.begin() + filterIndex);
    std::cout << "Successfully removed filter '" << filterName
              << "' from '" << imageName << "' at index " << filterIndex << "." << std::endl;
}

void ImageManager::showFilters(const std::string &imageName) const {
    int idx = findPipelineIndex(imageName);
    if (idx == -1) {
        std::cout << "Error! Image '" << imageName << "' not loaded." << std::endl;
        return;
    }
    const auto& pipe = pipelines[idx];
    if (pipe.filters.empty()) {
        std::cout << "No filters set for '" << imageName << "'." << std::endl;
        return;
    }
    std::cout << "Filters for '" << imageName << "' :" << std::endl;
    for (size_t i = 0; i < pipe.filters.size(); ++i) {
        std::cout << "[" << i << "]" << pipe.filters[i] -> getName() << std::endl;
    }
}

void ImageManager::showAllFilters() const {
    if (pipelines.empty()) {
        std::cout << "No images loaded in memory." << std::endl;
        return;
    }
    std::cout << "Current image pipelines:" << std::endl;
    for (const auto& pipe : pipelines) {
        std::cout << "Image: " << pipe.imageName << " ("
                  << pipe.image -> getWidth() << "x" << pipe.image -> getHeight() << ")" << std::endl;
        if (pipe.filters.empty()) {
            std::cout << "No filters added" << std::endl;
        }
        else {
            for (size_t i = 0; i < pipe.filters.size(); ++i) {
                std::cout << "[" << i << "]" << pipe.filters[i]->getName() << std::endl;
            }
        }
    }
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
    int idx = findPipelineIndex(imageName);
    if (idx == -1) {
        std::cout << "Error: Image '" << imageName << "' not loaded." << std::endl;
        return;
    }
    auto& pipe = pipelines[idx];
    if (!pipe.filters.empty()) {
        std::cout << "Applying remaining filters before saving..." << std::endl;
        for (const auto& f : pipe.filters) {
            f -> execute(*pipe.image);
        }
        pipe.filters.clear();
    }
    std::string finalName = outputName.empty() ? ("saved_" + pipe.imageName) : outputName;
    try {
        pipe.image -> save(finalName);
        std::cout << "Successfully saved result to " << finalName << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error saving result: " << e.what() << std::endl;
    }
}
