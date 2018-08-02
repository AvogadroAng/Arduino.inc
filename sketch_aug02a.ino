/*
Tutorial of Analog IR Sensor.
Prepared by Robo India.
www.roboindia.com
 */

int analog_ip = A0;   // select the input pin Photo Diode.
int inputVal = 0;     // to store photo diode input


void setup() {
  Serial.begin(9600);   // Setup Serial Communication.               
  Serial.print("ROBO INDIA\nroboindia.com\nTutorial on Analog IR Sensor.\n");  
}

void loop(){
    inputVal = analogRead(analog_ip); // Reading and storing analog input value.

        Serial.print("Input Value:");
        Serial.print(inputVal);       // Printing Analog input value of Photo Diode.
        Serial.print("\n");           // moving to new line
        delay(500);                   // Waiting for a while.

  
  
}
