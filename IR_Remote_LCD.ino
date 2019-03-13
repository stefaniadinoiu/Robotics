//IR Remote with LCD display

#include <IRremote.h>
#include <LiquidCrystal.h>
#define V0_PIN 9 // PWN in loc de POTENTIOMETRU
#define RECV_PIN 10


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(2, 1);

  pinMode(V0_PIN, OUTPUT); // PWN in loc de POTENTIOMETRU
  analogWrite(V0_PIN, 90);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("CH-");
          break;
          case 0xFF629D:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("CH");
          break;
          case 0xFFE21D:
          lcd.setCursor(1,1);
          lcd.clear();
         lcd.print("CH+");
          break;
          case 0xFF22DD:
          lcd.setCursor(1,1);
          lcd.clear();
         lcd.print("|<<");
          break;
          case 0xFF02FD:
          lcd.setCursor(1,1);
          lcd.clear();
         lcd.print(">>|");
          break ;  
          case 0xFFC23D:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print(">|");
          break ;               
          case 0xFFE01F:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("-");
          break ;  
          case 0xFFA857:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("+");
          break ;  
          case 0xFF906F:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("EQ");
          break ;  
          case 0xFF6897:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("0");
          break ;  
          case 0xFF9867:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("100+");
          break ;
          case 0xFFB04F:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("200+");
          break ;
          case 0xFF30CF:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("1");
          break ;
          case 0xFF18E7:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("2");
          break ;
          case 0xFF7A85:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("3");
          break ;
          case 0xFF10EF:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("4");
          break ;
          case 0xFF38C7:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("5");
          break ;
          case 0xFF5AA5:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("6");
          break ;
          case 0xFF42BD:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("7");
          break ;
          case 0xFF4AB5:
          lcd.setCursor(1,1);
          lcd.clear();
          lcd.print("8");
          break ;
          case 0xFF52AD:
          lcd.setCursor(1,1);
          lcd.clear();
         lcd.print("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
