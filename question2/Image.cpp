#include <exception>
#include <stdexcept>
#include "Image.h"

Image::Image(int nRows, int nCols) {
    this->img = std::vector<std::vector<Pixel *> >(nRows,
                                                   std::vector<Pixel *>(nCols));
}

Image::~Image() = default;

Pixel *Image::get(int row, int col) {
    Pixel *pix = this->img[row][col];
    return pix;
}

void Image::set(int row, int col, Pixel pix) {
    this->img[row][col] = &pix;
}