//7 segments display

#define PIN_A 8
#define PIN_B 7
#define PIN_C 5
#define PIN_D 4
#define PIN_E 3
#define PIN_F 9
#define PIN_G 10

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

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
}
void loop() {
  for (int i = 0; i < 10; i++) {
     writeNumber(i);
     delay(300);
  }
  for (int i = 9; i >= 0; i--) {
     writeNumber(i);
     delay(300);
  }
}

void writeNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], numbers[num][i]);
  }
}
