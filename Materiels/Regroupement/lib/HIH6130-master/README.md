HIH6130
=======

Arduino library for the [Honeywell HIH6130 Relative Humidity and Temperature Sensor] (http://www.digikey.com/product-detail/en/HIH6130-021-001/480-3651-2-ND/2704701). 

### Dependencies

1. Wire.h

### Installation

To install the HIH6130 library:

1. Download the zip file (bottom right) or clone the repository
2. Click `Sketch >> Import Library >> Add Library...`
3. Look at the example file located in the examples folder

### License

This library is licensed under the MIT license. Use it! Fix it! Develop it!

### Documentation

After installation, the sensor must be wired correctly to the Arduino. A breakout board for the sensor can be found [here] (https://upverter.com/hagandh/a3b0c6fa730e94e7/HIH6130/). 

#### Sample Script

    #include <Wire.h>
    #include <HIH6130.h>
    
    //define the address used by the HIH6130 sensor (default is 0x27)
    byte address = 0x27;
    
    //Set up an instance of the sensor
    HIH6130 rht(address);
    
    void setup(){
      Serial.begin(9600);
      Serial.println("RH\tTemperature (C)");
    }
    
    void loop(){
      // Read the data -> stored to public variables
      rht.readRHT();
      
      // Access the variables and print to serial monitor
      Serial.print(rht.humidity); Serial.print("\t");
      Serial.println(rht.temperature);
    }

### Discussion and Development

If you are interested in contributing, fork the repository and send pull requests as normal (for GitHub).
