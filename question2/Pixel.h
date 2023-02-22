#ifndef COSC1076_A3_PIXEL_H
#define COSC1076_A3_PIXEL_H

//minimum and maximum values for pixel
#define PIX_MIN 0
#define PIX_MAX 255
/*                                           */
/* This is an abstract class that describe   */
/* the general concepts of a pixel           */
/*                                           */

class Pixel{
public:    

    // get the brightness of the pixel
    virtual unsigned int getBrightness() const = 0;

    //[] operator to access a channel in the pixel
    virtual unsigned int& operator[](const char channel) = 0;

private:
    
};

#endif //COSC1076_A3_PIXEL_H