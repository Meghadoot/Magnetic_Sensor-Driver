#include <Magnetic_Flux_Sensor.h>

const int pin = 5;
sensor_units_t unit = GAUSS;
Magnetic_Flux_Sensor mfs(pin, unit);

void setup() 
{
 Serial.begin(9600);
}


void loop()
{
poles pole = mfs.poleDetector();
Serial.print("Detected magnetic pole is:");
Serial.print(pole);
}


