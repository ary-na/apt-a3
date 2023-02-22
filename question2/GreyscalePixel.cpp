#include "GreyscalePixel.h"
#include <exception>
#include <stdexcept>

GreyscalePixel::GreyscalePixel() {
    this->intensity = 0;
}

GreyscalePixel::GreyscalePixel(unsigned int intensity) {
    this->intensity = intensity;
}

GreyscalePixel::~GreyscalePixel() = default;

unsigned int GreyscalePixel::getBrightness() const {
    return this->intensity;
}

unsigned int &GreyscalePixel::operator[](const char channel) {
    if (channel == 'i') {
        return this->intensity;
    } else {
        throw std::invalid_argument("Invalid argument provided");
    }
}