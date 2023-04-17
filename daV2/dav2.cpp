/*
c++ code to calculate density altitude. User enters absolute pressure in inches of mercury, temperature in Fahrenheit, and humidity
The output first gives pressure altitude using PA (ft) = ( 29.92 - AltSet.(in/hg) ) * 1000 + FieldElev.(ft),
then density altitude using DA (ft) = PresAlt.(ft) + 118.8 * ( OAT(°C) - ISA(°C) ).
*/
#include <iostream>

// Standard atmosphere parameters
const double ISA_SEA_LEVEL_TEMP = 15.0; // Standard sea level temperature in Celsius
const double LAPSE_RATE = 0.002;        // Lapse rate in Celsius per foot

int main()
{
    double altitude, pressure, temperature;
    double pressureAltitude, densityAltitude;

    // Get user input for altitude, pressure, and temperature
    std::cout << "Enter altitude (ft): ";
    std::cin >> altitude;
    std::cout << "Enter absolute pressure (inHg): ";
    std::cin >> pressure;
    std::cout << "Enter temperature (F): ";
    std::cin >> temperature;

    // Convert temperature from Fahrenheit to Celsius
    temperature = (temperature - 32) * 5 / 9;

    // Calculate pressure altitude
    double altimeterSetting = 29.92;  // Standard altimeter setting
    double fieldElevation = altitude; // Field elevation is the same as altitude in this case
    pressureAltitude = (altimeterSetting - pressure) * 1000 + fieldElevation;

    // Calculate density altitude
    double ISA_temp = ISA_SEA_LEVEL_TEMP - LAPSE_RATE * altitude; // ISA temperature at given altitude
    densityAltitude = pressureAltitude + 118.8 * (temperature - ISA_temp);

    // Output results
    std::cout << "Pressure altitude (ft): " << pressureAltitude << std::endl;
    std::cout << "Density altitude (ft): " << densityAltitude << std::endl;

    return 0;
}
