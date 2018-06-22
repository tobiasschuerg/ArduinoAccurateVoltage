/*
  AnalogVoltage.h - Library for making accurate adc reading on Arduino.

  Based on a Blog entry by majenko.
  https://hackingmajenkoblog.wordpress.com/2016/02/01/making-accurate-adc-readings-on-the-arduino/

  Created by Tobias Schürg
*/

#ifndef TMP36_h
#define TMP36_h

long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA, ADSC));
  result = ADCL;
  result |= ADCH << 8;
  // result = 1125300L / result; // Back-calculate AVcc in mV
  result = 1100L * 1023 / result;
  return result;
}

double getVoltage(int pin, boolean debug) {
  double vcc = readVcc() / 1000.0;
  double reading = analogRead(pin) ;
  double voltage = (reading * vcc) / 1024.0;
  if (debug) {
    Serial.print("VCC: ");
    Serial.print(vcc , 3 );
    Serial.print(", raw reading:");
    Serial.print(reading , 3 );
    Serial.print(", raw voltage:");
    double rawVoltage = reading * 5 / 1024;
    Serial.print(rawVoltage , 3 );
    Serial.print(", adjusted voltage:");
    Serial.println(voltage , 3 );
  }
  return voltage;
}

double getVoltage(int pin) {
  return getVoltage(pin, false);
}


#endif



