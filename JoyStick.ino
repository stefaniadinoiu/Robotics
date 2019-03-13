//Joystick

#define SW_PIN 2 // digital pin connected to switch output
#define X_PIN A0 // analog pin connected to X output
#define Y_PIN A1 // analog pin connected to Y output

int switch_value;
int xValue, yValue;

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  switchValue = digitalRead(SW_PIN);
  xValue = analogRead(X_PIN);
  yValue = analogRead(Y_PIN);

  Serial.print("Switch:  ");
  Serial.print(switchValue);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(yValue);
  Serial.print("\n\n");
  delay(500);
}
