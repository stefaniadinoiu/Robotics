// Servo motor 

//DC Motor - Driver L293D
//Rotate DC motor one way
int motorpin1 = 2;                  //define digital output pin no.
int motorpin2 = 4;                  //define digital output pin no.

void setup () {

  pinMode(motorpin1,OUTPUT);         //set pin 2 as output
  pinMode(motorpin2,OUTPUT);        // set pin 4 as output

}
int motorpin1 = 2;                  //define digital output pin no.
int motorpin2 = 4;                  //define digital output pin no.
int controlMotorPin = 6;


int motorSpeed = 0;
int motorVoltage = 0;
int motorSpeedValue =0 ;

void setup () {

  Serial.begin(9600);
  pinMode(motorpin1,OUTPUT);         //set pin 2 as output
  pinMode(motorpin2,OUTPUT);        // set pin 4 as output
  digitalWrite(motorpin1,LOW);
  digitalWrite(motorpin2,HIGH);

}

void loop () {

  if (Serial.available())
  {
    
    motorSpeed = Serial.parseInt();
    motorSpeed = constrain(motorSpeed, 110, 255);
    analogWrite(controlMotorPin, motorSpeed);
    Serial.print("Speed: ");
    Serial.println(motorSpeed);
    
  }
}
