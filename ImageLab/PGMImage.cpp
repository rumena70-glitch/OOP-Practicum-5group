#include "PGMImage.h"

#include <fstream>

void PGMImage::load(const std::string &path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open PGM file: " + path);
    }
    std::string magic;
    file >> magic;
    if (magic != "P2" && magic != "P5") {
        throw std::runtime_error("Invalid PGM format");
    }
    file >> this -> width >> this -> height;
    file >> this -> maxValue;
    file.get();
    pixels.resize(width * height);
    if (magic == "P2") {
        int value;
        for (size_t i = 0; i < width * height; ++i) {
            if (!(file >> value)) {
                throw std::runtime_error("Invalid data in P2 file");
            }
            pixels[i] = (unsigned char) value;
        }
    }
    else {
        for (size_t i = 0; i < width * height; ++i) {
            int byte = file.get();
            pixels[i] = (unsigned char) byte;
        }
    }
    this -> filePath = path;
}

void PGMImage::save(const std::string &path) {
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + path);
    }
    file << "P5" << std::endl << width << " " << height << std::endl << maxValue << std::endl;
    for (const auto& pixelValue : pixels) {
        file.put(pixelValue);
    }
}

Pixel PGMImage::getPixel(size_t x, size_t y) const {
    unsigned char gray = pixels[y * width + x];
    return { gray, gray, gray };
}

void PGMImage::setPixel(size_t x, size_t y, const Pixel &p) {
    auto gray = (unsigned char) (0.299 * p.r + 0.587 * p.g + 0.114 * p.b);
    pixels[y * width + x] = gray;
}
