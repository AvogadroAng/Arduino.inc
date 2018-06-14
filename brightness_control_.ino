const int LED = 6;
int bgt = 0, i;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(i = 0; i <= 255; i++)
  {
    analogWrite(LED, i);
    delay(30);
  }

  for(i = 255; i >= 0; i--)
  {
    analogWrite(LED, i);
    delay(30);
  }

  delay(30);
}
