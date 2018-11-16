/*
 *CO-ORDINATE SPACE :
 *
 *   x|__0___|__1___|
 * y  |      |      |
 * 0  |(7,9) |(8,9) | 
 * 1  |(7,10)|(8,10)|
 * 
 * 
 *ASSOCIATE LEDS' :
 * 
 * PIN no. | co-ordinate
 *   5     |     (7,9) 
 *   6     |     (8,9)
 *   12    |    (7,10)
 *   13    |    (8,10)
 *   
 */

////////////////////////////////////////////////////////////////////////////////////////// DECLARATION SPACE ///////////////////////////////////////////////////////////////////////////////////////////////////////

//        0  1          0   1           
int x[]= {7, 8), y[] = {9, 10};   // Co-ordinate pins

//           0  1   2   3
int led[] = {5, 6, 12, 13};       // Virtual Led 

int x_ = 0, y_ = 0;               // constants

const int x_up = 0, x_down = 1, y_up = 2, y_down = 3; // Virtual Buttons

////////////////////////////////////////////////////////////////////////////////////////// SETUP SPACE (AND APPENDAGES) ////////////////////////////////////////////////////////////////////////////////////////////

void setup() {

Serial.begin(9600);
pinMode(x_up, INPUT);
pinMode(x_down, INPUT);
pinMode(y_up, INPUT);
pinMode(y_down, INPUT);

for(int i = 0; i < 4; i++)
{
  pinMode(led[i], INPUT); // setting leds' to input state.
}

// setting co-ordinate space to output state.
for(int i = 0; i < 2; i++)
{
  pinMode(x[i], OUTPUT); // x co-ordinate
}

for(int i = 0; i < 2; i++)
{
  pinMode(y[i], OUTPUT); // y co-ordinate
}

digitalWrite(x[x_], HIGH);
digitalWrite(y[y_], HIGH);

printer();
}

///////////////////////////////////////////////////////////////////////////////////////// RUNNER SPACE (AND APPENDAGES) /////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

//changing the state of "x_"

digitalWrite(x[x_], LOW);
digitalWrite(y[y_], LOW);

if(digitalRead(x_up) > 200)
{
  x_ = x_ - 1;
  
  if(x_ < 0)
  {
    x_ = 0;
  }
}
if(digitalRead(x_down) > 200)
{
  x_ = x_ + 1;
  
  if(x_ > 1)
  {
    x_ = 1;
  }
}

// changing the state of "y_"

if(digitalRead(y_up) > 200)
{
  y_ = y_ - 1;
  if(y_ < 0)
  {
    y_ = 0;
  }
}
if(digitalRead(y_down) > 200)
{
  y_ = y_ + 1;
  if(y_ > 1)
  {
    y_ = 1;
  }
}
digitalWrite(x[x_], HIGH);
digitalWrite(y[y_], HIGH);

printer();
}

void printer(){
  for(int i = 0; i < 4; i++)
  {
    if(digitalRead(led[i]) > 200)
    {
      Serial.print("(" + x_ + "," + y_ + ") = 1");
    }
  }
}








