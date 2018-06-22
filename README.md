# ArduinoAccurateVoltage

After trying multiple things to get good sensor readings (such as using resistors, capacitors, etc...) I came accross a [Blog entry by majenko](
 https://hackingmajenkoblog.wordpress.com/2016/02/01/making-accurate-adc-readings-on-the-arduino/), who uses the internal reference voltage to get accurate readings.


## usage

```
double voltage = getVoltage(A0);
Serial.println(voltage, DEC);
```
> 0.7257656097

To print some additional debug information to the Serial, set the debug flag to `true`:
```
getVoltage(A0, true);
```

> VCC: 5.161, raw reading:144.000, raw voltage:0.703, adjusted voltage:0.726  
