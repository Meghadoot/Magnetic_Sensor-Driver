# Magnetic-Sensor
This is a library for the Magnetic sensor (driver) designed specifically to work with all Arduino Boards.


## Table of Contents

1. [Magnetic Sensor](#MagneticSensor)
2. [Table of Contents](#table-of-contents)
3. [Summary](#summary)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Contributing](#contributing)
7. [History](#history)
8. [License](#license)

<snippet>
<content>
  

## Summary

Magnetic-flux sensors/Hall-effect sensors (such as [Allegro A1301](https://www.allegromicro.com/de-DE/Products/Magnetic-Linear-And-Angular-Position-Sensor-ICs/Linear-Position-Sensor-ICs/A1301-2.aspx), [Allegro A1302](https://www.allegromicro.com/de-DE/Products/Magnetic-Linear-And-Angular-Position-Sensor-ICs/Linear-Position-Sensor-ICs/A1301-2.aspx), [Honeywell HMC5883L](https://www.digikey.de/product-detail/de/honeywell-microelectronics-precision-sensors/HMC5883L-TR/342-1082-1-ND/2507853), [Allegro UGN3503](http://www.alldatasheet.com/datasheet-pdf/pdf/55100/ALLEGRO/UGN3503.html), [Honeywell SS49E](https://www.mouser.de/ProductDetail/?qs=%2Ffq2y7sSKcJBD3o5K2Vcgg==)) to measure the magnetic field in the viscinity or detection of magnetic pole. Internal ADC is used to calculate the exact value of analog magnetic flux from raw measured reading.


## Installation

To use this library download the zip file or clone the repository, decompress it to a folder named Current Sensor. Move the folder to {Arduino Path}/libraries.

## Usage

* Include the library at the top of your Arduino script. `#include <Magnetic_Flux_Sensor>`
* Create a global or local variable. 
  
 `Magnetic_Flux_Sensor mfs(Analog_pin)`
  ```
   *  Analog_pin: Any Analog Pin on Arduino Board 
  ```
 
* Read the exact Magnetic-flux value in Gauss.

 `float current = mfs.calculateMagneticField()`
 
## Contributing

1. Fork the project.
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request.

## History

- Dec  26, 2018   - Version 1.0.0 released (Readme Updated)

## License

GNU GPL, see License.txt

