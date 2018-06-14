// Servo Control Tutorial#1
// Prepared by Robo India
// www.roboindia.com

// Arduino Servo Library can add up to 12 servo on most of Arduino boards.
#include <Servo.h>  // Includes servo library.
 
Servo servo_1;      // Creating Servo object.
 
int servo_pos = 0;   // Storing servo position (0 degree to 180 degree)
 
void setup() 
{ 
  servo_1.attach(3);  // Attaching servo to Pin No.3 
} 
 
 
void loop() 
{ 
  servo_1.write(0);

  for(servo_pos = 0; servo_pos <= 180; servo_pos++){
    servo_1.write(servo_pos);
    delay(10);
  }
  delay(1000);
  for(servo_pos = 180; servo_pos <=0 ; servo_pos--){
    servo_1.write(servo_pos);
    delay(10);
  }
} 
