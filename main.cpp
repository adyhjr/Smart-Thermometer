#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

// Header file includes prototypes of functions and namespaces
// containing variables defined in implementation file.
#include "Interpolate.h"


// Declaring directives to make code readable
using namespace RGBValue;
using namespace Bounds;

int main() {
// Take the users input for temperature
auto temperature = 0; // This value within the formula is denoted by 'x'
std::cout << "Enter your temperature from [0, 100]: ";
std::cin >> temperature;

// While loop to ensure user inputs valid data
while (std::cin.fail()) {
    dataValidate();
    std::cout << "Invalid input, try again: ";
    std::cin >> temperature;
}
// While loop validate user input is within parameter
while (temperature < lowerBound || temperature > upperBound) {
    dataValidate();
    std::cout << "Not within range, try again: ";
    std::cin >> temperature;
}


// Conditional statement to specify RGB values based on temperature
if (temperature >= 0 && temperature <= 25) {
     lowerBound = 0;
     upperBound = 25;
     lowBlueValue = 255; // Red and green values remain at 0, denotes blue
     highGreenValue = 255; // Red value remains at 0, denotes cyan
     highBlueValue = 255;

} else if (temperature >= 25 && temperature <= 50) {
    lowerBound = 25;
    upperBound = 50;
    lowGreenValue = 255; // Red values remains at 0, denotes cyan
    lowBlueValue = 255;
    highGreenValue = 255;

} else if (temperature >= 50 && temperature <= 75) {
    lowerBound = 50;
    upperBound = 75;
    lowGreenValue = 255; // Value denotes green
    highRedValue = 255; // Values denote Yellow
    highGreenValue = 255;

} else if (temperature >= 75 && temperature <= 100) {
    lowerBound = 75;
    upperBound = 100;
    lowRedValue = 255; // Values denote yellow
    lowGreenValue = 255;
    highRedValue = 255; // Value denotes red

}

// This the dependent variable "Z" in the formula  Z = (x – a) / (b – a)
double tempRatio = zFormula (temperature, lowerBound, upperBound);

// Each color is interpolated using formula Y = dZ + c(1 – Z)
auto interpolatedRed = static_cast<int>(highRedValue * tempRatio + lowRedValue * (1 - tempRatio));
auto interpolatedGreen = static_cast<int>(highGreenValue * tempRatio + lowGreenValue * (1 - tempRatio));
auto interpolatedBlue = static_cast<int>(highBlueValue * tempRatio + lowBlueValue * (1 - tempRatio));



// Final outputs for calculations
std::cout << "Temperature is: " << temperature << '\n';

std::cout << "Hex code #";
hexConvert(interpolatedRed, interpolatedGreen, interpolatedBlue);

auto colorNumber = colorNumConvert(interpolatedRed, interpolatedGreen, interpolatedBlue);
std::cout << "Color #: " << colorNumber << std::endl;

return 0;

}

