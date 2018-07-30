#include <Servo.h>

////////////////////////////////////////////////////////////////////////////////
//                                    Notes
//
// Board: Elegoo MEGA2560 R3 (Arduino Mega)
// Motor: Suppo 1200kv Brushless Motor BL-2217/7
// ESC: Suppo Model SP-30A BEC 3A
// Power: benchtop DC power supply (11.1v)
// Potentiometer: 10k
//
// Wiring:
//   Arduino signal pin to ESC signal pin
//   Arduino ground pin to ESC ground pin
//   5v, ground, A0 to potentiometer
// 
// Servo.writeMicroseconds - Writes a value in microseconds (uS) to the servo, 
//   controlling the shaft accordingly. On a standard servo, this will set the 
//   angle of the shaft. On standard servos a parameter value of 1000 is fully 
//   counter-clockwise, 2000 is fully clockwise, and 1500 is in the middle. 
////////////////////////////////////////////////////////////////////////////////

#define SIGNAL_PIN 8

Servo esc;

void setup()
{
   esc.attach(SIGNAL_PIN); //attach ESC signal to pin 8
   esc.writeMicroseconds(1000); //init esc to (standard) lowest value 
   Serial.begin(9600);
}

void loop()
{
   int val = analogRead(A0); //A0 conntected to 10k potentiometer
   val = map(val, 0, 1023, 1000, 2000);
   esc.writeMicroseconds(val);
}
