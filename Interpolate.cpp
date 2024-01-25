#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "Interpolate.h"

const int c16BitColorBase = 65536; // Constant for 16-bit color
const int cColorRange = 256; // Color range constant

/// Global variables stored here:
/// Upper bound: temperature of 100
/// Lower bound: temperature of 0
// Bounds specifically for temperature within namespace
namespace Bounds {
    auto lowerBound = 0;
    auto upperBound = 100;
}
/// Values ranging from the lower and upper bounds
/// of RGB values used to interpolate
// RGB values within namespace
namespace RGBValue {
    auto lowRedValue = 0;
    auto lowGreenValue = 0;
    auto lowBlueValue = 0;
    auto highRedValue = 0;
    auto highGreenValue = 0;
    auto highBlueValue = 0;
}

/// Function converts interpolated color values to its respective color number
/// red, green, and blue are all the interpolated values calculated in main.
int colorNumConvert (double red, double green, double blue ) {
    return c16BitColorBase * red + cColorRange * green + blue;
}

/// Validates user input specifically the user's input for temperature in the program
void dataValidate() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// Converts interpolated values to hex values
/// uses io manipulation library to correctly display hex color
/// conversionRed, conversionGreen, conversionBlue are all interpolated in main
void hexConvert(int conversionRed, int conversionGreen, int conversionBlue) {
        std::stringstream stream;
        // Included io manipulation to output correct values
        stream << std::setfill ('0') << std::setw(2) << std::hex << conversionRed
               << std::setfill ('0') << std::setw(2) << std::hex << conversionGreen
               << std::setfill ('0') << std::setw(2) << std::hex << conversionBlue;
        std::cout << stream.str() << std::endl;
}

/// Denoted as the dependent variable in Z = (x – a) / (b – a)
double zFormula (int temperature, int lowerBound, int upperBound) {
        return static_cast<double>(temperature - lowerBound)
               / (upperBound - lowerBound);
}
