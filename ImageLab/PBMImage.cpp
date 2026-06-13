#include "PBMImage.h"

#include <fstream>

void PBMImage::load(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open PBM file: " + path);
    }
    std::string magic;
    file >> magic;
    if (magic != "P1") {
        throw std::runtime_error("Invalid PBM format");
    }
    file >> this -> width >> this -> height;
    pixels.resize(width * height);
    int bit;
    for (size_t i = 0; i < width * height; ++i) {
        if (!(file >> bit)) {
            throw std::runtime_error("Invalid data in P1 file");
        }
        pixels[i] = (bit == 1);
    }

    this -> filePath = path;
}

void PBMImage::save(const std::string &path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + path);
    }
    file << "P1" << std::endl << width << " " << height << std::endl;
    for (size_t i = 0; i < pixels.size(); ++i) {
        file << (pixels[i] ? "1" : "0") << " ";
        if ((i + 1) % width == 0) {
            file << std::endl;
        }
    }
}

Pixel PBMImage::getPixel(size_t x, size_t y) const {
    bool isBlack = pixels[y * width + x];
    if (isBlack) {
        return { 0, 0, 0 };
    }
    else {
        return { 255, 255, 255 };
    }
}

void PBMImage::setPixel(size_t x, size_t y, const Pixel &p) {
    auto gray = (unsigned char) (0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
    pixels[y * width + x] = (gray < 128);
}
