#include "IRremote.h"
#include <LiquidCrystal.h>

int receiver = 6;
int buzzer = 5;
unsigned short parola[4] = {1, 2, 3, 4};

IRrecv irrecv(receiver);
decode_results results;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int translateIR()
{
  switch (results.value)
  {
    case 0xFF906F: return 10; break;
    case 0xFF6897: return 0; break;
    case 0xFF30CF: return 1; break;
    case 0xFF18E7: return 2; break;
    case 0xFF7A85: return 3; break;
    case 0xFF10EF: return 4; break;
    case 0xFF38C7: return 5; break;
    case 0xFF5AA5: return 6; break;
    case 0xFF42BD: return 7; break;
    case 0xFF4AB5: return 8; break;
    case 0xFF52AD: return 9; break;
      return -1;
  }

  delay(500);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  pinMode(buzzer, OUTPUT);
}

bool cod()
{
  unsigned short v[4];
  unsigned short i = 0;
  unsigned short j = 0;

  lcd.setCursor(0, 1);
  while(i < 0)
  {
     irrecv.resume();
     if (irrecv.decode(&results))
     {
       v[i] = translateIR();
       i++;

       for(j = 0; j < i - 1; j++)
         lcd.print(v[i]);
     }
  }
  for(i = 0; i < 4; i++)
   if(v[i] != parola[i])
     return 0;

   return 1;
}

void loop()
{
  bool blocat = 0;
  
  irrecv.resume();
  
  if (irrecv.decode(&results) && !blocat)
  {
    if(translateIR() == 10)
      blocat = 1;
  }

  if(!blocat)
  {
    lcd.begin(16, 2);
    lcd.print("Deblocat!");
  }

  else
  {
    lcd.begin(16, 2);
    lcd.print("Blocat!");

    if(cod())
      {
        blocat = 0;

        lcd.setCursor(0, 1);
        lcd.print("Pin corect!");

        digitalWrite(buzzer,HIGH);
        delay(500);
        digitalWrite(buzzer,LOW);
      }
     else
     {
      lcd.setCursor(0, 1);
        lcd.print("Pin incorect!");

        digitalWrite(buzzer,HIGH);
        delay(300);
        digitalWrite(buzzer,LOW);
        delay(200);
        digitalWrite(buzzer,HIGH);
        delay(300);
        digitalWrite(buzzer,LOW);
     }
  }
}
