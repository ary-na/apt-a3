#include <exception>
#include <stdexcept>
#include "RGBPixel.h"

RGBPixel::RGBPixel() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

RGBPixel::RGBPixel(unsigned int r, unsigned int g, unsigned int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGBPixel::~RGBPixel() = default;

unsigned int RGBPixel::getBrightness() const {
    return (this->r + this->g + this->b) / 3;
}

unsigned int &RGBPixel::operator[](const char channel) {
    if (channel == 'r') {
        return this->r;
    } else if (channel == 'g') {
        return this->g;
    } else if (channel == 'b') {
        return this->b;
    } else {
        throw std::invalid_argument("Invalid argument provided!");
    }
}