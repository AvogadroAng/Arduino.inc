//Code checked corret
/*
 * MI => Master Input & Slave Output
 * MO => Master Output & Slave Input
 * DATA => pin for transmitting data
 * CLK => Clock 
 * 
 * WORKING PRINCIPAL:
 * when the (MI)master input is high, i.e. the slave sends requests for the data be send
 * the master first turns the (MO)Master Output high, completing the handshaking
 * now periodically, with a phased delay, clock(CLK) is set high
 * when the clock is turned high the DATA pin i turned high or low 
 * according to the binary representation of each character of the given string
 * 
 * NOTE:
 * No input statement is specified. To change the message sent mutat the string st.
 */

String st = "hello World!!";
char ch;
int arr[8] = {0};
int MI = 2, MO = 13, DATA = 4, CLK = 5;

void setup() {
  // initializations done here
Serial.begin(9600);
pinMode(MO, OUTPUT);
pinMode(MI, INPUT);
pinMode(DATA, OUTPUT);
pinMode(CLK, OUTPUT);

}

void loop() {
  //HAND_SHAKING PROTOCALL/////////////////////////////////////////////////////////////////////
  if (digitalRead(MI)==HIGH)
  {
    digitalWrite(MO, HIGH);

  /////////////////////////////////////////////////////////////////////////////////////////////
    delay(100);
    data();
    digitalWrite(MO, LOW); // terminating handshake
  }
}

void data()
{
  for(int j,k,i = 0; i<st.length(); i++)
{
  ch = st[i];
  /*
   * This snippet changes a char to int
   * Then converts it to binary
   */
  for(k = (int)ch, j = 0; j < 8;j++)
  {
    /*
     * bitwise& and bit right shift operator is used 
     * example: x = a(110 0001) & 1 = 1
     *          y = a(110 0001) >> 1 = 0(11 0000)
     */
    arr[j] = k & 1;
    k = k >> 1;
    digitalWrite(CLK, HIGH);
    digitalWrite(DATA, 255*arr[j]);
    Serial.print(arr[j]);
    delay(100);
    digitalWrite(DATA, LOW);
    digitalWrite(CLK, LOW);
  }
  Serial.println();
  }
}
