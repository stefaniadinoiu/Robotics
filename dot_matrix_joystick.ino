// Controlling one dot on a 8x8 matrix using a joystick


#include "LedControl.h" 
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
#define x_pin A0
#define y_pin A1


void writeNumber(int);
int currentNumber = 0;
int joyMoved = 0;

int i;

// JOYSTICK
const int joyX = A0;
const int joyY = A1;

int prevX = 3, prevY = 3, posX = 3, posY = 3;
int valX, valY;
boolean movedX = false, movedY = false;


 
void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 2); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int xValue = analogRead(x_pin);
  int yValue = analogRead(y_pin);
  //Serial.println(xValue);

 valX = analogRead(joyX);
  valY = analogRead(joyY);


  if (valY < 400)
  {
    if (movedY == false)
    {
      prevY = posY;
      posY--;
      movedY = true;
    }
  }
  else
  {
    if (valY > 600)
    {
      if (movedY == false)
      {
        prevY = posY;
        posY++;
        movedY = true;
      }
    }
    else movedY = false;
  }

  if (valX < 400)
  {
    if (movedX == false)
    {
      prevX = posX;
      posX--;
      movedX = true;
    }
  }
  else
  {
    if (valX > 600)
    {
      if (movedX == false)
      {
        prevX = posX;
        posX++;
        movedX = true;
      }
    }
    else movedX = false;
  }

  // daca depaseste marginile, sa intre inapoi in matrice
  if (posY == 8) posY = 0;
  if (posY == -1) posY = 7;

  if (posX == 8) posX = 0;
  if (posX == -1) posX = 7;

 lc.setLed(0, posX, posY, true);
 delay(50);
  lc.setLed(0, posX, posY, false);

}


 
 
