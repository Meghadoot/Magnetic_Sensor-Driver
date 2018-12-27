#include <Magnetic_Flux_Sensor.h>

const int pin = 5;
sensor_units_t unit = TESLA;
Magnetic_Flux_Sensor mfs(pin, unit);

void setup() 
{
 Serial.begin(9600);
}


void loop()
{
long flux = mfs.calculateMagneticField();
Serial.print("Measured magnetic flux is:");
Serial.print(flux);
}


