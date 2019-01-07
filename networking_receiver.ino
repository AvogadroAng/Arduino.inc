//Code checked faulty
/*
 * SO => Master Input & Slave Output
 * SI => Master Output & Slave Input
 * DATA => pin for transmitting data
 * CLK => Clock 
 * 
 * WORKING PRINCIPAL:
 * Slave output(SO) is made high, i.e. the slave sends requests for the data be send
 * the master first turns the (MO)Master Output high, completing the handshaking
 * now periodically, with a phased delay, clock(CLK) is Sensed
 * when the clock is high the DATA pin takes in HIGH or LOW
 * the array is defined according to the data sent
 * then the binary is converted into decimal and then to string
 * 
 * NOTE:
 * No input statement is specified. To change the message sent mutat the string st in the Master board.
 */

char ch ="";
int arr[8] = {0};
int SO = 2, SI = 13, DATA = 4, CLK = 5, request = 7, k=0;

void setup() {
  // Initialization here
Serial.begin(9600);

pinMode(SO, OUTPUT);
pinMode(request, INPUT);
pinMode(SI, INPUT);
pinMode(DATA, INPUT);
pinMode(CLK, INPUT);
}

void loop() {
  // users request to send data.
if(digitalRead(request)==HIGH)
{  
//HANDSHAKING PROTOCALL/////////////////////////////////////////////////////////////
digitalWrite(SO, HIGH);
}
if(digitalRead(SI)==HIGH)
{
  digitalWrite(SO, LOW);
  delay(100);
////////////////////////////////////////////////////////////////////////////////////
  READ();
}
}

void READ()
{
  int i = 0;
  while(digitalRead(SI) == HIGH)
  {
    while(i < 8) //serves as a check as there is no delay.....* even if there is a data sent it waits
    {            //                                           * data is not misplaced in the array
      if(digitalRead(CLK) == HIGH)
      {//checks out unwanted data
          if(digitalRead(DATA)== HIGH)
          {
            arr[i] = 1;
          }
          else
          {
            arr[i] = 0;
          }
          Serial.print(arr[i]);
          /*
           * bit left shift operator is used...
           * example: x = 0(11 0000) << 1 = @(110 0000)
           */
          k += arr[i] << i;
          i++;
      }
    }
    ch = (char)k;
    Serial.print(ch);
    k = 0;
    i=0;
  }
}
