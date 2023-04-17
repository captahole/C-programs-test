/*
c++ code to calculate density altitude. User enters altitude in feet, absolute pressure in inches of mercury, temperature in Fahrenheit.
The out put first gives pressure altitude using PA (ft) = ( 29.92 - AltSet.(in/hg) ) * 1000 + FieldElev.(ft),
then density altitude using DA (ft) = PresAlt.(ft) + 118.8 * ( OAT(°C) - ISA(°C) ).
pascal value of say 100734 and divide by 3386.39 you'll get 29.72 inches-Hg.
problem is bme280 reports absolute pressure, need baro for this program.
see below to covert
*/
#include <iostream>
using namespace std;

int main()
{
    double altitude, Pressure, temperature;
    double pressureAltitude, densityAltitude;

    // Get user inputs
    cout << "Enter altitude (ft): ";
    cin >> altitude;
    cout << "Enter pressure (inHg): ";
    cin >> Pressure;
    cout << "Enter temperature (°F): ";
    cin >> temperature;


    // Calculate pressure altitude
    double fieldElevation = altitude;
    pressureAltitude = (29.92 - Pressure) * 1000 + fieldElevation;

    // Calculate density altitude
    double oatCelsius = (temperature - 32) * 5 / 9;      // Convert temperature from °F to °C
    double isaCelsius = (15 - (1.98 * altitude / 1000)); // ISA temperature lapse rate
    densityAltitude = pressureAltitude + 118.8 * (oatCelsius - isaCelsius);

    // Output results
    cout << "Pressure altitude (ft): " << pressureAltitude << endl;
    cout << "Density altitude (ft): " << densityAltitude << endl;
    cout << "---------------------------------- " << endl;
    cout << "oat-c" << oatCelsius << endl;
    cout << "isa-c " << isaCelsius << endl;

    return 0;
}
/*
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Create an instance of the BME280 sensor
Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  // Initialize the BME280 sensor
  if (!bme.begin(0x76)) { // Change the address to 0x77 if your sensor uses that address
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // Read absolute pressure from the BME280 sensor
  float absolutePressure = bme.readPressure() / 100.0F; // Divide by 100 to convert from Pa to hPa

  // Calculate barometric pressure using BME280 compensation formula
  float seaLevelPressure = 1013.25; // Standard sea level pressure in hPa
  float barometricPressure = absolutePressure / pow(1 - (bme.readAltitude(1013.25) * 0.0065 / 288.15), 5.2561);

  // Output results
  Serial.print("Absolute Pressure (hPa): ");
  Serial.println(absolutePressure);
  Serial.print("Barometric Pressure (hPa): ");
  Serial.println(barometricPressure);

  delay(1000); // Delay for 1 second
}

*/