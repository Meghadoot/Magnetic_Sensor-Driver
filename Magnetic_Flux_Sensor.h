/***************************************************************************
	Magnetic_Flux_Sensor.h
	Author: Meghadoot
  	2018-12-27
	
	This is a library for the Magnetic Flux sensor.
	Magnetic Flux sensor or Hall-effect sensor provides analog output, ADC is required to interface.
	Designed specifically to work with the Arduino Boards.


    * Pin Layout SIP(UA) Package for Honeywell SS49E Series Linear Hall-effect sensor 
    =================================================================================
    1  |   VCC     |  4.5V-10V
    2  |   GND     |
    3  |   signal  |  connected to Analog Pin 
	
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

#ifndef _Magnetic_Flux_Sensor_h
#define _Magnetic_Flux_Sensor_h

#include "Arduino.h"

/*=========================================================================
    MACRO DECLARATIONS
    -----------------------------------------------------------------------*/
    #define MAX_OUTPUT        5.0
    #define MAX_RANGE         1023.0
    #define MIN_OUTPUT        0.01 
    #define MIN_RANGE         0.0

    #define NOFIELD           505L    // Analog output with no applied field, calibrate this
    #define TOMILLIGAUSS      3488L  // For SS49E: 1.4mV/Gauss i.e. 0.28672steps, and 1024 analog steps = 5V, so 1 step = 3488mG
	
    #define __Magnetic_Flux_Sensor_debug           DISABLED
/*=========================================================================*/

/**
 * @brief Sensor reading unit type.
 */
typedef enum sensor_units 
{
	GAUSS,				/**< Gauss */
	TESLA				/**< Tesla */
} sensor_units_t;

/**
 * @brief Magnetic poles.
 */
typedef enum  
{
    NORTH,              /**< North Pole */       
    SOUTH               /**< South Pole */    
} poles;        

class Magnetic_Flux_Sensor
{
  public:
  	Magnetic_Flux_Sensor(int pin);	/**< constructor */						
    Magnetic_Flux_Sensor(int pin, sensor_units_t unit);	/**< constructor */	
    long calculateMagneticField();	
    poles poleDetector();	

  private:
    int _pin;							/**< Analog Pin number */	
    sensor_units_t _unit;				/**< Measurement Unit */	
};

#endif

