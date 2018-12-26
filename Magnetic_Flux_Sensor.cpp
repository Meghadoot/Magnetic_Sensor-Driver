/***************************************************************************
	Magnetic_Flux_Sensor.h
	Author: Meghadoot
  2018-12-27
	

  * Pin Layout SIP(UA) Package for Honeywell SS49E Series Linear Hall-effect sensor 
  =================================================================================
  1  |   VCC     |  4.5V-10V
  2  |   GND     |
  3  |   signal  |  connected to Analog Pin 


	This is a library for the Magnetic Flux sensor.
	Magnetic Flux sensor or Hall-effect sensor provides analog output, ADC is required to interface.
	Designed specifically to work with the Arduino Boards.
	
  Copyright (C) 2018  Meghadoot Gardi.  All right reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

 ***************************************************************************/

#include "Arduino.h"
#include "Magnetic_Flux_Sensor.h"

/***************************************************************************
 CONSTRUCTORS
 ***************************************************************************/

/****************************************************************************
** Function name:           Magnetic_Flux_Sensor
** Descriptions:            set pin and pin mode
****************************************************************************/

Magnetic_Flux_Sensor::Magnetic_Flux_Sensor(int pin)
{
  pinMode(pin, INPUT);
  _pin  = pin;
  _unit = GAUSS;
}

/****************************************************************************
** Function name:           Magnetic_Flux_Sensor
** Descriptions:            set pin, pin mode and unit of measurement  
****************************************************************************/

Magnetic_Flux_Sensor::Magnetic_Flux_Sensor(int pin, sensor_units_t unit)
{
  pinMode(pin, INPUT);
  _pin  = pin;
  _unit = unit;
}

/***************************************************************************
 PUBLIC FUNCTIONS
 ***************************************************************************/

/******************************************************************************
** Function name:           calculateMagneticField
** Descriptions:            read sensor value and measure magnetic flux 
*******************************************************************************/

long Magnetic_Flux_Sensor::calculateMagneticField()
{
  long magnetic_field, magnetic_field_tesla;
  int sensorValue = analogRead(_pin); //read the Analog pin passed value
  
  #if(__Magnetic_Flux_Sensor_debug == ENABLED)
    Serial.print("Raw reading: ");
    Serial.println(sensorValue);
  #endif
  
  long compensated = sensorValue - NOFIELD;  // adjust relative to no applied field
  long magnetic_field_gauss = compensated * TOMILLIGAUSS / 1000;   // adjust scale to Gauss 

  switch(_unit)
  {
    case GAUSS:       
        #if(__Magnetic_Flux_Sensor_debug == ENABLED)
          Serial.print("Magnetic Flux = ");
          Serial.print(magnetic_field_gauss);
          Serial.println(" Gauss");
        #endif
        magnetic_field = magnetic_field_gauss;
    break; 

    case TESLA:
        magnetic_field_tesla = 10000 * magnetic_field_gauss;
        #if(__Magnetic_Flux_Sensor_debug == ENABLED)
          Serial.print("Magnetic Flux = ");
          Serial.print(magnetic_field_tesla);
          Serial.println(" Tesla");
        #endif
        magnetic_field = magnetic_field_tesla;
    break;

    default:
        // Choose proper unit.
    break;

  }
  
  return magnetic_field;  
}

/******************************************************************************
** Function name:           poleDetector
** Descriptions:            calculate polarity based on magnetic field reading 
*******************************************************************************/

poles Magnetic_Flux_Sensor::poleDetector() 
{
	long magnetic_flux = calculateMagneticField();

  if(magnetic_flux > 0)
  {
    Serial.println("South pole");
	  return SOUTH;
  }
  else if(magnetic_flux < 0)
  {
    Serial.println("North pole");
	  return NORTH;	
  }
  else
  {
    Serial.println("Equator");
  }
}


