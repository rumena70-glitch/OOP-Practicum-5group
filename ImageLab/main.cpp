#include <iostream>
#include <sstream>

#include "BlurFilter.h"
#include "ImageManager.h"
#include "PPMImage.h"
#include "NegativeFilter.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "SharpenFilter.h"

int main() {
    ImageManager engine;
    std::string line;

    std::cout << "  Welcome to ImageLab" << std::endl;
    std::cout << "Available commands: load, add-filter, run, run-all, quit" << std::endl;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            break;
        }

        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "quit") {
            std::cout << "Exiting ImageLab. Goodbye!" << std::endl;
            break;
        }
        else if (command == "load") {
            std::string path;
            ss >> path;
            if (path.empty()) {
                std::cout << "Error: 'load' command requires a file path. Usage: load <path>" << std::endl;
            }
            else {
                engine.loadImage(path);
            }
        }
        else if (command == "add-filter") {
            std::string imageName, filterName;
            ss >> imageName >> filterName;
            if (imageName.empty() || filterName.empty()) {
                std::cout << "Error: Usage: add-filter <image-name> <filter-name>" << std::endl;
            }
            else {
                engine.addFilter(imageName, filterName);
            }
        }
        else if (command == "run") {
            std::string imageName;
            ss >> imageName;
            if (imageName.empty()) {
                std::cout << "Error: 'run' command requires an image name. Usage: run <image-name>" << std::endl;
            }
            else {
                engine.run(imageName);
            }
        }
        else if (command == "run-all") {
            engine.runAll();
        }
        else if (command == "show-filters") {
            std::string imageName;
            ss >> imageName;
            if (imageName.empty()) {
                std::cout << "Error: Usage: show-filters <image-name>" << std::endl;
            }
            else {
                engine.showFilters(imageName);
            }
        }
        else if (command == "show-all-filters") {
            engine.showAllFilters();
        }
        else if (command == "remove-filter") {
            std::string imageName;
            size_t filterIndex;
            if (!(ss >> imageName >> filterIndex)) {
                std::cout << "Error: Usage: remove-filter <image-name> <filter-index>" << std::endl;
            }
            else {
                engine.removeFilter(imageName, filterIndex);
            }
        }
        else if (command == "save") {
            std::string imageName, outputName;
            ss >> imageName;
            if (ss >> outputName) {
                engine.save(imageName, outputName);
            }
            else {
                if (imageName.empty()) {
                    std::cout << "Error! Image name not entered." << std::endl;
                }
                else {
                    engine.save(imageName, "");
                }
            }
        }
        else {
            std::cout << "Error: Unknown command '" << command << "'. Please try again." << std::endl;
        }
    }

}
