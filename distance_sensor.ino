// ultrasonic distance sensor 

#define PIN_LED 10
//# define PIN_POT A5
#define TRIG 11
#define ECHO 12
void setup() {
  pinMode(PIN_LED,OUTPUT);
//  pinMode(PIN_POT, INPUT);
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
}

void loop() {

  /*digitalWrite(PIN_LED,HIGH);
  delay(250);
  digitalWrite(PIN_LED,LOW);
  delay(250);*/

 /* int value_pot = analogRead(PIN_POT);
  Serial.println(value_pot);
  //analogWrite(PIN_LED, value_pot);

  int mappet_value = map(value_pot, 0, 1023, 0, 255);
  analogWrite(PIN_LED, mappet_value);*/

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  int timp = pulseIn(ECHO, HIGH);
  int distanta = timp*0.034/2;
  Serial.println(distanta); // in cm;

  if(distanta < 5)
  digitalWrite(PIN_LED, HIGH);

    else 
       digitalWrite(PIN_LED, LOW);

}
