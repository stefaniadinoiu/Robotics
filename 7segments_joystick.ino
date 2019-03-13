// 7 Segments display controlled by joysticj


#define PIN_A 8
#define PIN_B 7
#define PIN_C 5
#define PIN_D 4
#define PIN_E 3
#define PIN_F 9
#define PIN_G 10
#define X_PIN A0
#define Y_PIN A1

int numbers[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

int segments[7] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
void writeNumber(int);
int currentNumber = 0;
Int joyMoved = 0;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  Serial.begin(9600);
}
void loop() {
  int xValue = analogRead(X_PIN);
  if (xValue > 1000 && joyMoved == 0) {
    if (currentNumber < 9) {
      currentNumber ++;
     }
  else {
    currentNumber = 0;
  }
  joyMoved = 1;
 }

 if (xValue < 100 && joyMoved == 0) {
   if (currentNumber > 0) {
     currentNumber--;
   }
   else {
     currentNumber = 9;
   }
  joyMoved = 1;
 }

 If (xValue < 600 && xValue > 400) {
   joyMoved = 0;
 } 

 writeNumber(currentNumber);
}

void writeNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], numbers[num][i]);
  }
}
