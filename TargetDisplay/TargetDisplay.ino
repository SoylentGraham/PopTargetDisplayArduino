/*
  gr: for OSX remember, use USB hub as macbook usb3 doesn't 
  like arduinos and needs to be downgraded

  for digispark, need to change programmer to micronucleaus
 */


#include "DigiKeyboard.h"

int led = 1;  // Change to pin 1 for MODEL A

int LedDuration = 500;
int PrintDelay = 5000;

String RandomStrings[] = { "simon smells!", "bum!", "fart!", "pants!", "http://www.massiveboobs.com/yourmum.mp4" };

void setup() {
  pinMode(led, OUTPUT);
  DigiKeyboard.update();
}

void WriteString(String s)
{
  for ( int i=0;  i<s.length(); i++ )
  {
    DigiKeyboard.write(s[i]);
  }
}

void loop() {
  digitalWrite(led, 1);
  int RandomIndex = rand() % ( sizeof(RandomStrings)/sizeof(RandomStrings[0]) );
  WriteString( RandomStrings[RandomIndex] );
  delay(LedDuration);
  digitalWrite(led, 0);
  
  delay(PrintDelay - LedDuration);
}



