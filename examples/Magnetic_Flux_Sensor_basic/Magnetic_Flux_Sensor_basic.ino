#include <Magnetic_Flux_Sensor.h>

const int pin = 5;
Magnetic_Flux_Sensor mfs(pin);

void setup() 
{
 Serial.begin(9600);
}


void loop()
{
long flux = mfs.calculateMagneticField();
Serial.print("Measured magnetic flux is:");
Serial.print(flux);
Serial.println(" Gauss");
}


