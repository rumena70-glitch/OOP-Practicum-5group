#include "PPMImage.h"
#include <fstream>

void PPMImage::load(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    std::string magic;
    file >> magic;
    if (magic != "P3" && magic != "P6") {
        throw std::runtime_error("Invalid PPM format");
    }
    file >> this -> width >> this -> height;
    file >> this -> maxValue;
    file.get();
    pixels.resize(width * height);
    if (magic == "P3") {
        unsigned r, g, b;
        for (size_t i = 0; i < width * height; ++i) {
            file >> r >> g >> b;
            pixels[i] = { (unsigned char) r, (unsigned char) g, (unsigned char) b };
        }
    }
    else {
        for (size_t i = 0; i < width * height; ++i) {
            unsigned char r = file.get();
            unsigned char g = file.get();
            unsigned char b = file.get();
            pixels[i] = { r, g, b };
        }
    }
}

Pixel PPMImage::getPixel(size_t x, size_t y) const {
    return pixels[y * width + x];
}

void PPMImage::setPixel(size_t x, size_t y, const Pixel &p) {
    pixels[y * width + x] = p;
}

void PPMImage::save(const std::string& path) {
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + path);
    }
    file << "P6" << std::endl << width << " " << height << std::endl << maxValue << std::endl;
    for (const auto&[r, g, b] : pixels) {
        file.put(r);
        file.put(g);
        file.put(b);
    }
}
