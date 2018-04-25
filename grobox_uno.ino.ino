#include <Wire.h>
#include <I2C_LCD.h>
#include "DS1307.h"

//For detials of the function useage, please refer to "I2C_LCD User Manual".
//You can download the "I2C_LCD User Manual" from I2C_LCD WIKI page:
//                              http://www.seeedstudio.com/wiki/I2C_LCD

I2C_LCD LCD;         //define a object of I2C_LCD class
uint8_t I2C_LCD_ADDRESS = 0x51;    //Device address configuration, the default value is 0x51.

extern GUI_Bitmap_t bmlogo;       //Declare bitmap data packet.
/*
  char monthTab[13][6] = {"Null", "Jan.,", "Fev.,", "Mar.,", "Avr.,", "Mai,", "Jun.,", "Jul.,",
                        "Aou.,", "Sep.,", "Oct.,", "Nov.,", "Dec.,"
                       };
  char weekTab[8][10] = {"Null", "Lun.,", "Mar.,", "Mer.,", "Jeu.,", "Ven.,", "Sam.,", "Sun.,"};
  char dayTab[32][6] = {"Null", "1st,", "2nd,", "3rd,", "4th,", "5th,",
                      "6th,", "7th,", "8th,", "9th,", "10th,",
                      "11th,", "12th,", "13th,", "14th,", "15th,",
                      "16th,", "17th,", "18th,", "19th,", "20th,",
                      "21th,", "22nd,", "23rd,", "24th,", "25th,",
                      "26th,", "27th,", "28th,", "29th,", "30th,", "31st,"
                     };
*/
char timeTab[10] = {"00:00:00"};

#define BUTTON 8
#define RELAY 2
#define BUZZER 3

//const int RELAY = 2; //Relay set to digital pin 2
//const int tonePin = 3;  // arbitrary for arduino boards, set this to whatever you want
const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin
int dst = 10;
int state =0;

DS1307 clock;       //define a object of DS1307 class

void setup()
{

  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  Wire.begin();   //I2C controller initialization.
  clock.begin();  //RTC initialization.
  Serial.println("initializing ");

  /* clock.fillByYMD(2015, 07, 26);  //Jul 31,2015
    clock.fillByHMS(22, 30, 30);    //21:20:30"
    clock.fillDayOfWeek(SUN);       //Friday
    clock.setTime();    //Write time to the RTC chip.
  */
}

void loop()
{
  LCD.CleanAll(WHITE);    //Clean the screen with black or white.

  //Booting logo OFF, backlight ON, bitmap work mode.
  //If you want to display characters please switch to WM_CharMode.
  LCD.WorkingModeConf(OFF, ON, WM_BitmapMode);

  //Display bitmap at the specified location.
  //Prototype: void DrawScreenAreaAt(GUI_Bitmap_t *bitmap, uint8_t x, uint8_t y)
  LCD.DrawScreenAreaAt(&bmlogo, 4, 3);

  //Draw a rectangle, and filled with black;
  //Prototype: void DrawRectangleAt(x, y, width, height, mode);
  LCD.DrawRectangleAt(0, 0, 128, 4, BLACK_FILL);
  LCD.DrawRectangleAt(0, 60, 128, 4, BLACK_FILL);

  //Booting logo ON, backlight ON, character work mode.
  LCD.WorkingModeConf(ON, ON, WM_CharMode);

// vews
while (1)
state = digitalRead(BUTTON);
//DEFAULT view
  {
    //Update the date and time.
    clock.getTime();

    //Set font size.
    LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
    //LCD.FontModeConf(Font_10x20, FM_ANL_AAA, BLACK_BAC);
    //Set the start coordinate.
    LCD.CharGotoXY(60, 20);

    //Date format: Fri.,24st,Jul.,2015 // chandge to 01/01/1970
    // LCD.print(weekTab[clock.dayOfWeek]);
    LCD.print(clock.dayOfMonth);
    LCD.print("/");
    LCD.print(clock.month);
    LCD.print("/");
    LCD.print(clock.year + 2000);

    //Set font size.
    LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
    //Set the start coordinate.
    LCD.CharGotoXY(60, 10);

    //Time format: 00:00:00
    snprintf(timeTab, 9, "%02d:%02d:%02d", clock.hour, clock.minute, clock.second);
    LCD.print(timeTab);

    //display temperature
    //Set font size.
    LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
    //Set the start coordinate.
    LCD.CharGotoXY(60, 30);

    LCD.print("Temp:");
    LCD.print("22.05");

    //display temperature
    //Set font size.
    LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
    //Set the start coordinate.
    LCD.CharGotoXY(67, 40);

    LCD.print("Gas:");
    LCD.print(analogRead(gasPin));

    //display soil moisture
    //Set font size.
    LCD.FontModeConf(Font_6x8, FM_ANL_AAA, BLACK_BAC);
    //Set the start coordinate.
    LCD.CharGotoXY(67, 50);

    LCD.print("Day:");
    LCD.print(dst);


    // add automatism

    if (clock.hour == 22 && clock.minute == 40 && clock.second == 40) {
      digitalWrite(RELAY, HIGH);   // turn the Relay on (HIGH is the voltage level)
      Serial.println("Alarm: - turn lights on");
      tone(BUZZER, 1000);
      delay(1000);
      noTone(BUZZER);
    }

    if (clock.hour == 23 && clock.minute == 00 && clock.second == 50) {
      digitalWrite(RELAY, LOW);   // turn the Relay off (LOW is the voltage level)
      Serial.println("Alarm: - turn lights off");
      tone(BUZZER, 1000);
      delay(1000);
      noTone(BUZZER);
    }

    if (clock.hour == 00 && clock.minute == 00 && clock.second == 00) {
      Serial.print("Days since start: ");
      delay(1000);
      Serial.println(dst);
      Serial.println("it's midnight Dr Schweitzer we increment 1 day since start");
      dst++;;
      Serial.print("Days since start: ");
      Serial.println(dst);
    }

    if (clock.second == 30) {
      Serial.print("Days since start: ");
      delay(1000);
      Serial.println(dst);
      Serial.print("Gas sensor: ");
      Serial.println(analogRead(gasPin));
    }



    //delay(1000);
  }
}

