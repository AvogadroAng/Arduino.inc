

int x[]= {7, 8), y[] = {9, 10}, x_ = 0, y_ = 0;

const int x_up = 2, x_down = 3, y_up = 4, y_down = 5; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(x_up, INPUT);
pinMode(x_down, INPUT);
pinMode(y_up, INPUT);
pinMode(y_down, INPUT);

for(int i = 0; i < 2; i++)
{
  pinMode(x[i], INPUT);
}

for(int i = 0; i < 2; i++)
{
  pinMode(y[i], INPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(x_up) > 200)
{
  x_ = x_ - 1;
  
  if(x_ < 0)
  {
    x_ = 1;
  }
}
if(digitalRead(x_down) > 200)
{
  x_ = x_ + 1;
  
  if(x_ > 1)
  {
    x_ = 0;
  }
}
if(y_up > 200)
{
  y_up = y_up - 1;
}
}



























