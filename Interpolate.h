//
// Created by Adolfo Hernandez on 10/1/23.
//

#ifndef INTERPOLATE_H
#define INTERPOLATE_H


/// For this program, the objective is to simulate the effects of
/// a smart thermometer that alternates in color based
/// on the temperature it reads. The colors vary using the RGB
/// scale. Colors will be fully saturated. The formula to
/// interpolate between values is:
///  Z = (x – a) / (b – a)
/// Y = dZ + c(1 – Z)

// TEST code:
// DISPLAYS RGB VALUES std::cout << "RBG values are: (" << interpolatedRed << ","
//<< interpolatedGreen << "," <<  interpolatedBlue << ")" << std::endl;


// Color conversion function using interpolated RGB values
int colorNumConvert (double red, double green, double blue );

// Data validation function
void dataValidate();

// Hex conversion function using interpolated RGB values based on temperature
// Included io manipulation to output correct values
void hexConvert(int conversionRed, int conversionGreen, int conversionBlue);

//  This function gives you the ratio 'Z' in the interpolation formula.
//  It is denoted as Z = (x – a) / (b – a)
 double zFormula (int temperature, int lowerBound, int upperBound);

// Namespace to include parameters of temperature
// extern keyword used to extend scope of variables throughout files
// Source: https://learn.microsoft.com/en-us/cpp/cpp/extern-cpp?view=msvc-170
namespace Bounds {
   extern int lowerBound; // This constant is the lower bound of temperature --variable 'a'
   extern int upperBound; // This constant is the upper bound temperature -- varable 'b'
}

// Namespace to organize RGB values
namespace RGBValue {
   extern int lowRedValue;
   extern int lowGreenValue;
   extern int lowBlueValue;
   extern int highRedValue;
   extern int highGreenValue;
   extern int highBlueValue;
}

#endif //INTERPOLATE_H