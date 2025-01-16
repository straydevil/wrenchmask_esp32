/** straydevil's fork of TomMakesThings's wrenchmask, now supporting ESP32's onboard bluetooth. **/

#include <LedControl.h>
#include <BluetoothSerial.h>

LedControl led=LedControl(19,21,22,2);
BluetoothSerial SerialBT;

unsigned long transitionTime=5;
unsigned long blinkTime=200;  
unsigned long longblinkTime=400;
unsigned long shortTime=800;
unsigned long normalTime=2000;
unsigned long longTime=6000;


String currentValue = "key1";

int frame = 0;

String data = "";

int maxBrightness = 5;

int textSpeed = 50;

String characterMessage = "DEDSEC";

int maxMessageSize = 30;

int characterMessagePointer = 0;


byte customLED[] = 
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};


byte X[] = 
{ 
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110,
  B11000011,
  B00000000
};


byte wink[] =
{
  B00000000,
  B00011000,
  B00011000,
  B00111100,
  B00100100,
  B01100110,
  B01000010,
  B11000011
};

byte wink_blink[] =
{
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01100110,
  B11000011,
  B00000000,
  B00000000
};


byte wink_reverse[] =
{
  B11000011,
  B01000010,
  B01100110,
  B00100100,
  B00111100,
  B00011000,
  B00011000,
  B00000000
};


byte rightwink[] = 
{
  B10000000,
  B11100000,
  B00111000,
  B00001110,
  B00001110,
  B00111000,
  B11100000,
  B10000000
};


byte leftwink[] = 
{
  B00000001,
  B00000111,
  B00011100,
  B01110000,
  B01110000,
  B00011100,
  B00000111,
  B00000001
};


byte right_slash[] =
{
  B00000011,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B11000000,
  B10000000
};


byte left_slash[] =
{
  B11000000,
  B01100000,
  B00110000,
  B00011000,
  B00001100,
  B00000110,
  B00000011,
  B00000001
};



byte question[] =
{
  B00111100,
  B01111110,
  B01100110,
  B00000110,
  B00011100,
  B00011000,
  B00000000,
  B00011000
};



byte hashtag[] = 
{
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100
};


byte heart[] =
{
  B00000000,
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};

byte heart2[] =
{
  B00000000,
  B01100110,
  B11111111,
  B11011011,
  B11000011,
  B01100110,
  B00111100,
  B00011000
};

byte heart3[] =
{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};


byte equal[] =
{
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000
};


byte tilde[] =
{
  B00000000,
  B00000000,
  B01110000,
  B11111001,
  B10011111,
  B00001110,
  B00000000,
  B00000000
};


byte minus[] =
{
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};


byte dollar[] =
{
  B00010000,
  B00111100,
  B01010010,
  B01010000,
  B00111100,
  B00010010,
  B01010010,
  B00111100
};


byte exclamation[] = 
{
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00011000
};


byte O[] = 
{
  B00111100,
  B01000010,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00111100
};


byte smallo[] = 
{
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B00100100,
  B00011000,
  B00000000
};


byte at[] =
{
  B00111100,
  B01000010,
  B10011101,
  B10100101,
  B10100101,
  B10011010,
  B01000000,
  B00111110
};


byte semicolon[] =
{
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00001000,
  B00010000
};

byte semicolonblink[] =
{
  B00000000,
  B00111100,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00001000,
  B00010000
};


byte nineEye[] =
{
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00011100,
  B00000100,
  B00100100,
  B00011000
};

В¬_В¬
byte negation[] = 
{
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000011,
  B00000011,
  B00000000,
  B00000000
};


byte tripleDot[] =
{
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B11011011,
  B00000000,
  B00000000,
  B00000000
};

byte tripleDotBlink[] =
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B00000000,
  B00000000,
  B00000000
};


byte star[] =
{
  B00000000,
  B00010000,
  B01010100,
  B00111000,
  B00010000,
  B00101000,
  B01000100,
  B00000000
};

byte bracket[] =
{
  B00000000,
  B00000000,
  B10000001,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

byte bracketBlink[] =
{
  B00000000,
  B00000000,
  B00000000,
  B10000001,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

byte invader1a[] =
{
   B00011000,  
   B00111100,
   B01111110,
   B11011011,
   B11111111,
   B00100100,
   B01011010,
   B10100101
};

byte invader1b[] =
{
  B00011000, 
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte invader2a[] =
{
  B00100100, 
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

byte invader2b[] =
{
  B00100100, 
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};


byte t[] =
{
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte lenny[] =
{
  B00000000,
  B00000000,
  B01111110,
  B11001001,
  B01001000,
  B00110000,
  B00000000,
  B00000000
};

byte musicNote[] =
{
  B00001100,
  B00001110,
  B00001011,
  B00001001,
  B00001000,
  B00111000,
  B01111000,
  B00110000
};


byte leftQuote[] =
{
  B00000000,
  B01101100,
  B01101100,
  B01001000,
  B01001000,
  B00100100,
  B00000000,
  B00000000
};


byte rightQuote[] =
{
  B00000000,
  B00110110,
  B00110110,
  B00010010,
  B00010010,
  B00100100,
  B00000000,
  B00000000
};


byte leftApostrophe[] =
{
  B00000000,
  B00100000,
  B00110000,
  B00011000,
  B00001000,
  B00000000,
  B00000000,
  B00000000
};


byte rightApostrophe[] =
{
  B00000000,
  B00000100,
  B00001100,
  B00011000,
  B00010000,
  B00000000,
  B00000000,
  B00000000
};

byte leftApostropheBlink[] = 
{
  B00000000,
  B00000000,
  B00100000,
  B00010000,
  B00001000,
  B00000000,
  B00000000,
  B00000000
};

byte rightApostropheBlink[] =
{
  B00000000,
  B00000000,
  B00000100,
  B00001000,
  B00010000,
  B00000000,
  B00000000,
  B00000000
};

byte rectangle[] =
{
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00111100
};


byte plus[] =
{
  B00011000,
  B00011000,
  B00011000,
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000
};


byte leftArrow1[] =
{
  B00000000,
  B00100000,
  B01100000,
  B11111111,
  B01100000,
  B00100000,
  B00000000,
  B00000000
};

byte leftArrow2[] =
{
  B00000000,
  B00000000,
  B00100000,
  B01100000,
  B11111111,
  B01100000,
  B00100000,
  B00000000
};


byte rightArrow1[] =
{
  B00000000,
  B00000100,
  B00000110,
  B11111111,
  B00000110,
  B00000100,
  B00000000,
  B00000000
};

byte rightArrow2[] = 
{
  B00000000,
  B00000000,
  B00000100,
  B00000110,
  B11111111,
  B00000110,
  B00000100,
  B00000000
};

byte refresh1[] =
{
  B00111101,
  B01000011,
  B10000111,
  B10000000,
  B00000001,
  B11100001,
  B11000010,
  B10111100
};

byte refresh2[] =
{
  B11101100,
  B01100010,
  B10100001,
  B10000001,
  B10000001,
  B10000101,
  B01000110,
  B00110111
};

byte charge1[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11000001,
  B11000001,
  B11000001,
  B11111111,
  B00000000
};

byte charge2[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11100001,
  B11100001,
  B11100001,
  B11111111,
  B00000000
};

byte charge3[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11110001,
  B11110001,
  B11110001,
  B11111111,
  B00000000
};

byte charge4[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111001,
  B11111001,
  B11111001,
  B11111111,
  B00000000
};

byte charge5[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111101,
  B11111101,
  B11111101,
  B11111111,
  B00000000
};

byte charge6[] =
{
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B00000000
};

byte tick[] =
{
  B00000000,
  B00000011,
  B00000110,
  B00001100,
  B11011000,
  B01110000,
  B00100000,
  B00000000
};

byte pacman1[] =
{
  B00111100,
  B01111110,
  B00111011,
  B00011111,
  B00001111,
  B00011111,
  B01111110,
  B00111100
};

byte pacman2[] =
{
  B00111100,
  B01111110,
  B11111011,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100
};

byte ghost1[] =
{
  B00111000,
  B01111100,
  B10010010,
  B11011010,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte ghost2[] =
{
  B00111000,
  B01111100,
  B10010010,
  B10110110,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte ghost3[] =
{
  B00111000,
  B01111100,
  B11011010,
  B10010010,
  B10010010,
  B11111110,
  B11111110,
  B10101010
};

byte colon[] =
{
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000
};

byte cute[] =
{
  B00111100,
  B01001110,
  B10011111,
  B10011111,
  B10011111,
  B10011111,
  B01001110,
  B00111100
};

byte n[] =
{
  B00111100,
  B01111110,
  B11100111,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011
};


byte u[] =
{
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100
};


byte z[] = 
{
  B11111111,
  B11111111,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01111111,
  B11111111
};

byte hollowSquare[] =
{
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};

byte aries[] =
{
  B01100110,
  B11111111,
  B10011001,
  B10011001,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte taurus[] =
{
  B00100010,
  B01010101,
  B00010100,
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00011100
};

byte gemini[] =
{
  B11111111,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B11111111
};

byte cancer[] =
{
  B01111110,
  B10010001,
  B10010001,
  B01100000,
  B00000110,
  B10001001,
  B10001001,
  B01111110
};

byte leo[] =
{
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  B01100101,
  B10010010,
  B10010000,
  B01100000
};

byte virgo[] =
{
  B00000000,
  B10111010,
  B01010101,
  B01010101,
  B01010101,
  B01000110,
  B01001100,
  B00010100
};

byte libra[] =
{
  B00111100,
  B01111110,
  B01000010,
  B01000010,
  B11100111,
  B00000000,
  B11111111,
  B00000000
};

byte scorpio[] =
{
  B00000000,
  B10111000,
  B01010100,
  B01010100,
  B01010100,
  B01000101,
  B01000101,
  B00000010
};

byte sagitarius[] =
{
  B00001111,
  B00000011,
  B00000101,
  B01001001,
  B00110000,
  B00110000,
  B01001000,
  B10000000
};

byte capricorn[] =
{
  B00000000,
  B10110000,
  B01001010,
  B01001101,
  B01001001,
  B01001010,
  B01001100,
  B00011000
};

byte aquarius[] =
{
  B00000000,
  B00000000,
  B01010101,
  B10101010,
  B00000000,
  B01010101,
  B10101010,
  B00000000
};

byte pisces[] =
{
  B11000011,
  B00100100,
  B00100100,
  B11111111,
  B00100100,
  B00100100,
  B00100100,
  B11000011
};

byte female[] =
{
  B00011100,
  B00100010,
  B00100010,
  B00100010,
  B00011100,
  B00001000,
  B00011100,
  B00001000
};

byte male[] =
{
  B00000111,
  B00000011,
  B00000101,
  B00111000,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte flashingSquare1[] =
{
  B11111111,
  B10000001,
  B10111101,
  B10100101,
  B10100101,
  B10111101,
  B10000001,
  B11111111
};

byte flashingSquare2[] =
{
  B00000000,
  B01111110,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B01111110,
  B00000000
};

byte roundLeft[] =
{
  B00111100,
  B01000010,
  B10110001,
  B10110001,
  B10110001,
  B10110001,
  B01000010,
  B00111100
};

byte roundCentre[] =
{
  B00111100,
  B01000010,
  B10011001,
  B10011001,
  B10011001,
  B10011001,
  B01000010,
  B00111100
};

byte roundRight[] =
{
  B00111100,
  B01000010,
  B10001101,
  B10001101,
  B10001101,
  B10001101,
  B01000010,
  B00111100
};

byte roundFull[] = 
{
  B00111100,
  B01000010,
  B10111101,
  B10111101,
  B10111101,
  B10111101,
  B01000010,
  B00111100
};

const PROGMEM byte alphabet[] = {
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B11111011, B11111011, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00000000, B00000011, B00000011, B00000000, B00000000, B00000000, 
  B00000000, B01111110, B11111111, B11000011, B11000011, B11111111, B01111110, B00000000, 
  B00000000, B00000000, B00000011, B11111111, B11111111, B11000011, B00000000, B00000000, 
  B00000000, B01110011, B11111011, B11001011, B11001111, B11001111, B01100111, B00000000, 
  B00000000, B01111110, B11111111, B11011011, B11011011, B11011011, B11000011, B00000000, 
  B00000100, B11111111, B11111111, B11000100, B01100100, B00111100, B00011100, B00000000, 
  B00000000, B11001110, B11011111, B11011011, B11011011, B11111011, B11111010, B00000000, 
  B00000000, B11001110, B11011111, B11011011, B11011011, B11111111, B11111110, B00000000, 
  B00000000, B11100000, B11110000, B11011000, B11001100, B11001111, B11000111, B00000000, 
  B00000000, B01110110, B11111111, B11001001, B11001001, B11111111, B01110110, B00000000, 
  B00000000, B01111110, B11111111, B11001011, B11001011, B11111011, B01110000, B00000000, 
  B00000000, B01111111, B11111111, B11001000, B11001000, B11111111, B01111111, B00000000, 
  B00000000, B01110111, B11111111, B11001001, B11001001, B11111111, B11111111, B00000000, 
  B00000000, B01100110, B11100111, B11000011, B11000011, B11111111, B01111110, B00000000, 
  B00000000, B01111110, B11111111, B11000011, B11000011, B11111111, B11111111, B00000000, 
  B00000000, B11000011, B11011011, B11011011, B11011011, B11111111, B11111111, B00000000, 
  B00000000, B11000000, B11011000, B11011000, B11011000, B11111111, B11111111, B00000000, 
  B00000000, B01101000, B11101111, B11001011, B11000011, B11111111, B01111110, B00000000, 
  B00000000, B11111111, B11111111, B00011000, B00011000, B11111111, B11111111, B00000000, 
  B00000000, B11000011, B11000011, B11111111, B11111111, B11000011, B11000011, B00000000, 
  B00000000, B11000000, B11000000, B11111111, B11111111, B11000011, B11000011, B00000000, 
  B00000000, B10000001, B11000011, B01100110, B00111100, B11111111, B11111111, B00000000, 
  B00000000, B00000011, B00000011, B00000011, B00000011, B11111111, B11111111, B00000000, 
  B01111111, B11111111, B01100000, B00111111, B01111111, B11100000, B11111111, B01111111, 
  B11111111, B11111111, B00000111, B00011110, B01111000, B11100000, B11111111, B11111111, 
  B00111100, B01111110, B11000011, B11000011, B11000011, B11000011, B01111110, B00111100, 
  B00000000, B01111000, B11111100, B11001100, B11001100, B11111111, B11111111, B00000000, 
  B00000001, B01111110, B11111111, B11001011, B11010011, B11000011, B11111111, B01111110, 
  B00000000, B01110001, B11111011, B11011110, B11011100, B11111111, B11111111, B00000000, 
  B00000000, B11001110, B11011111, B11011011, B11011011, B11111011, B01110011, B00000000, 
  B00000000, B11000000, B11000000, B11111111, B11111111, B11000000, B11000000, B00000000, 
  B00000000, B11111111, B11111111, B00000011, B00000011, B11111111, B11111111, B00000000, 
  B00000000, B11111100, B11111110, B00000111, B00000111, B11111110, B11111100, B00000000, 
  B11111110, B11111111, B00000011, B00011111, B00011111, B00000011, B11111111, B11111110, 
  B11000001, B01100011, B00110110, B00011100, B00011100, B00110110, B01100011, B11000001, 
  B10000000, B11100000, B11111000, B00011111, B00011111, B11111000, B11100000, B10000000, 
  B11000011, B11100011, B11110011, B11111011, B11011111, B11001111, B11000111, B11000011, 

};

void clearDisplays() {
  led.clearDisplay(0);
  led.clearDisplay(1);
}

boolean controlledDelay(unsigned long delayValue) {
  for (int i = 0; i < delayValue; i++) {
    if (Serial.peek() == '(') {
      return true;
    }
    delay(1);
  }
  return false;
}

void set_both_eyes(byte eye0[], byte eye1[])

{
  for (int i = 0; i < 8; i++)
  {
    led.setRow(0,i,eye0[i]);
    led.setRow(1,i,eye1[i]);
  }
}

void remove_eye_slow(byte eye[], int e)
{
  int limit = 8;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      
      led.setRow(e, j + (8-limit), eye[j]);
    }
    controlledDelay(transitionTime);
    led.clearDisplay(e);
    --limit;
  }
}

void remove_both_eyes_slow(byte eye0[], byte eye1[])
{
  int limit = 8;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      led.setRow(0, j + (8-limit), eye0[j]);
      led.setRow(1, j + (8-limit), eye1[j]);
    }
    controlledDelay(transitionTime);
    clearDisplays();
    --limit;
  }
}

void set_both_eyes_slow(byte eye0[], byte eye1[])
{
  int limit = 1;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      led.setRow(0, 7 - (j + (8-limit)), eye0[7-j]);
      led.setRow(1, 7 - (j + (8-limit)), eye1[7-j]);
    }
    controlledDelay(transitionTime);
    clearDisplays();
    ++limit;
  }
}

void set_both_eyes_slow_reverse(byte eye0[], byte eye1[])
{
  int limit = 1;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      led.setRow(0, j + (8-limit), eye0[j]);
      led.setRow(1, j + (8-limit), eye1[j]);
    }
    controlledDelay(transitionTime);
    clearDisplays();
    ++limit;
  }
}

void scrolling_eye(byte eye[], int e)
{
  int limit = 8;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      led.setColumn(e, 7 + (j + (8-limit)), eye[7-j]);
    }
    controlledDelay(textSpeed);
    clearDisplays();
    ++limit;
  }
  int limit2 = 7;
  for (int i = 0; i < 7; i++)
  {
    for (int j = limit2; j > -1; j--)
    {
      led.setColumn(e, 7 - (j + (8-limit2)), eye[j]);
    }
    controlledDelay(textSpeed);
    clearDisplays();
    --limit2;
  }
}

void scrolling_both_eyes(byte eye0[], byte eye1[])
{
  int limit = 8;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < limit; j++)
    {
      led.setColumn(0, 7 + (j + (8-limit)), eye0[7-j]);
      led.setColumn(1, 7 + (j + (8-limit)), eye1[7-j]);
    }
    controlledDelay(textSpeed);
    clearDisplays();
    ++limit;
  }
  int limit2 = 7;
  for (int i = 0; i < 7; i++)
  {
    for (int j = limit2; j > -1; j--)
    {
      led.setColumn(0, 7 - (j + (8-limit2)), eye0[j]);
      led.setColumn(1, 7 - (j + (8-limit2)), eye1[j]);
    }
    controlledDelay(textSpeed);
    clearDisplays();
    --limit2;
  }
}

void glitch_eyes()
{
  if (random(0, 200) == 0) {
    for (int i = 0; i < random(0, 20); i++) {
      set_both_eyes(exclamation, exclamation);
      for (int j = 0; j < random(0, 20); j++) {
        led.setLed(random(0, 2), random(0, 8), random(0, 8), true);
      }
      controlledDelay(blinkTime);
      clearDisplays();
      controlledDelay(blinkTime);
    }
  } else if (random(0, 1000) == 0) {
    set_both_eyes_slow(hashtag, hashtag);
    set_both_eyes(hashtag, hashtag);
    for (int j = 0; j < random(0, 20); j++) {
      led.setLed(random(0, 2), random(0, 8), random(0, 8), true);
      controlledDelay(random(10, 100));
    }
    controlledDelay(blinkTime);
    remove_both_eyes_slow(hashtag, hashtag);
  } else if (random(0, 1200) == 0) {
    bool a = true;
    set_both_eyes_slow(invader1a, invader2a);
    set_both_eyes(invader1a, invader2a);
    for (int j = 0; j < random(3, 20); j++) {
      if (a == true) {
        a = false;
        set_both_eyes(invader1a, invader2a);
      } else {
        a = true;
        set_both_eyes(invader1b, invader2b);
      }
      controlledDelay(blinkTime);
      for (int k = 0; k < random(0, 20); k++) {
        led.setLed(random(0, 2), random(0, 8), random(0, 8), true);
        controlledDelay(random(10, 100));
      }
    }
    controlledDelay(blinkTime);
    remove_both_eyes_slow(invader1a, invader2a);
  } else if (random(0, 500) == 0) {
    set_both_eyes_slow(X, X);
    set_both_eyes(X, X);
    controlledDelay(random(50, 3000));
    for (int j = 0; j < random(0, 100); j++) {
      led.setLed(random(0, 2), random(0, 8), random(0, 8), true);
      controlledDelay(random(10, 100));
    }
    remove_both_eyes_slow(X, X);
  } else {
      if (random(0,2) == 0) {
        led.setLed(random(0, 2), random(0, 8), random(0, 8), false);
      }
      else {
        led.setLed(random(0, 2), random(0, 8), random(0, 8), true);
      }
      controlledDelay(5);
  }
  controlledDelay(random(0, 3));
}

void wink_eyes()
{
  if (frame == 0) {
    frame = 1;
    set_both_eyes_slow(tilde, wink_reverse);
    set_both_eyes(tilde, wink_reverse);
    controlledDelay(normalTime);
    remove_both_eyes_slow(tilde, wink_reverse);
  }
  else {
    frame = 0;
    set_both_eyes_slow(wink, wink);
    set_both_eyes(wink, wink);
    controlledDelay(normalTime);
    remove_both_eyes_slow(wink, wink);
  }
}

void heart_eyes()
{
  if (frame == 0) {
    frame = 1;
    set_both_eyes_slow(heart, heart);
    set_both_eyes(heart, heart);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  else if (frame == 1) {
    frame = 2;
    set_both_eyes(heart2, heart2);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  else if (frame == 2) {
    frame = 3;
    set_both_eyes(heart3, heart3);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 3) {
    frame = 0;
    set_both_eyes(heart2, heart2);
    controlledDelay(longblinkTime);
    clearDisplays();
    remove_both_eyes_slow(heart, heart);
  }
}

void sleep_eyes()
{
  set_both_eyes_slow(z, z);
  set_both_eyes(z, z);
  for (double j = maxBrightness; j > 0; j -= 0.1) {
    led.setIntensity(0,j);
    led.setIntensity(1,j);
    if (controlledDelay(25)) {
      break;
    }
  }
  for (double i = 0; i <= maxBrightness; i += 0.1) {
    led.setIntensity(0,i);
    led.setIntensity(1,i);
    if (controlledDelay(25)) {
      break;
    }
  }
  led.setIntensity(0,maxBrightness);
  led.setIntensity(1,maxBrightness);
  remove_both_eyes_slow(z, z);
}

void shy_eyes()
{
  set_both_eyes(wink, wink);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(wink_blink, wink_blink);
  controlledDelay(blinkTime);
}

void money_eyes()
{
  for (int x = 0; x < random(5, 10); x++) {
    set_both_eyes(dollar, dollar);
    for (int j = maxBrightness; j > 0; j--) {
      led.setIntensity(0,j);
      led.setIntensity(1,j);
      if (controlledDelay(blinkTime)) {
        break;
      }
    }
    for (int i = 0; i <= maxBrightness; i++) {
      led.setIntensity(0,i);
      led.setIntensity(1,i);
      if (controlledDelay(blinkTime)) {
        break;
      }
  }
  led.setIntensity(0,maxBrightness);
  led.setIntensity(1,maxBrightness);
  clearDisplays();
  }
}

void cry_eyes()
{
  set_both_eyes(semicolon, semicolon);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(semicolonblink, semicolonblink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void uneven_round_eyes()
{
  if (frame == 0) {
    if (random(0, 2) == 0) {
      frame = 1;
    }
    generic_eyes(O, smallo);
  }
  else if (frame == 1) {
    frame = 2;
    generic_eyes(O, O);
  }
  else if (frame == 2) {
    if (random(0, 2) == 0) {
      frame = 3;
    }
    generic_eyes(smallo, O);
  }
  else if (frame == 3) {
    frame = 0;
    generic_eyes(O, O);
  }
}

void tripleDot_eyes()
{
  set_both_eyes(tripleDot, tripleDot);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(tripleDotBlink, tripleDotBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void bracket_eyes()
{
  set_both_eyes(bracket, bracket);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(bracketBlink, bracketBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void music_eyes()
{
  set_both_eyes(musicNote, musicNote);
  for (double j = maxBrightness; j > 0; j -= 0.1) {
    led.setIntensity(0,j);
    led.setIntensity(1,j);
    controlledDelay(30);
  }
  for (double i = 0; i <= maxBrightness; i += 0.1) {
    led.setIntensity(0,i);
    led.setIntensity(1,i);
    controlledDelay(30);
  }
  clearDisplays();
}

void apostrophe_eyes()
{
  set_both_eyes(leftApostrophe, rightApostrophe);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(leftApostropheBlink, rightApostropheBlink);
  controlledDelay(blinkTime);
  clearDisplays();
}

void swear_eyes()
{
  switch(random(0,6)) {
    case 0:
    set_both_eyes(hashtag, hashtag);
    break;

    case 1:
    set_both_eyes(dollar, dollar);
    break;

    case 2:
    set_both_eyes(star, star);
    break;

    case 3:
    set_both_eyes(at, at);
    break;

    case 4:
    set_both_eyes(question, question);
    break;

    case 5:
    set_both_eyes(exclamation, exclamation);
    break;
  }
  controlledDelay(blinkTime);
  clearDisplays();
}

void charge_eyes()
{
  set_both_eyes(charge1, charge1);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(charge2, charge2);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(charge3, charge3);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(charge4, charge4);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(charge5, charge5);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(charge6, charge6);
  controlledDelay(shortTime);
  clearDisplays();
}

void pacman_eyes()
{
  int character = random(0, 5);
  int side = random(0, 2);
  if (character == 0) {
    if (side == 0) {
        set_both_eyes_slow_reverse(pacman1, ghost2);
        set_both_eyes(pacman2, ghost2);
        controlledDelay(shortTime);
        set_both_eyes(pacman1, ghost1);
        controlledDelay(blinkTime);
        set_both_eyes(pacman2, ghost1);
        controlledDelay(shortTime);
        remove_both_eyes_slow(pacman1, ghost1);
    }
    else {
        set_both_eyes_slow(ghost2, pacman1);
        set_both_eyes(ghost2, pacman2);
        controlledDelay(shortTime);
        set_both_eyes(ghost2, pacman1);
        controlledDelay(blinkTime);
        set_both_eyes(ghost1, pacman2);
        controlledDelay(shortTime);
        remove_both_eyes_slow(ghost1, pacman1);
    }
  }
  else {
    if (side == 0) {
      set_both_eyes_slow(ghost1, ghost3);
    }
    else {
      set_both_eyes_slow_reverse(ghost1, ghost3);
    }
    set_both_eyes(ghost1, ghost3);
    controlledDelay(shortTime);
    set_both_eyes(ghost1, ghost1);
    controlledDelay(blinkTime);
    set_both_eyes(ghost2, ghost1);
    controlledDelay(shortTime);
    remove_both_eyes_slow(ghost1, ghost2);
  }
  set_both_eyes_slow(colon, colon);
  set_both_eyes(colon, colon);
  controlledDelay(longblinkTime);
  remove_both_eyes_slow(colon, colon);
  clearDisplays();
  }

void zodiac_eyes()
{
  if (frame == 0) {
    frame = 1;
    set_both_eyes(aries, aries);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 1) {
    frame = 2;
    set_both_eyes(taurus, taurus);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 2) {
    frame = 3;
    set_both_eyes(gemini, gemini);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 3) {
    frame = 4;
    set_both_eyes(cancer, cancer);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 4) {
    frame = 5;
    set_both_eyes(leo, leo);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 5) {
    frame = 6;
    set_both_eyes(virgo, virgo);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 6) {
    frame = 7;
    set_both_eyes(libra, libra);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 7) {
    frame = 8;
    set_both_eyes(scorpio, scorpio);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 8) {
    frame = 9;
    set_both_eyes(sagitarius, sagitarius);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 9) {
    frame = 10;
    set_both_eyes(capricorn, capricorn);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 10) {
    frame = 11;
    set_both_eyes(aquarius, aquarius);
    controlledDelay(shortTime);
    clearDisplays();
  }
  else if (frame == 11) {
    frame = 0;
    set_both_eyes(pisces, pisces);
    controlledDelay(shortTime);
    clearDisplays();
  }
}

void flashing_square_eyes()
{
  for (int i = 0; i < 5; i++) {
    set_both_eyes(flashingSquare1, flashingSquare1);
    controlledDelay(longblinkTime);
    clearDisplays();
    set_both_eyes(flashingSquare2, flashingSquare2);
    controlledDelay(longblinkTime);
    clearDisplays();
  }
  set_both_eyes(minus, minus);
  controlledDelay(blinkTime);
  clearDisplays();
}

void round_dot_eyes()
{
  int frame = random(0, 4);
  if (frame == 0) {
    generic_eyes(roundLeft, roundLeft);
  }
  else if (frame == 1) {
    generic_eyes(roundRight, roundRight);
  }
  else {
    generic_eyes(roundCentre, roundCentre);
  }
}

void generic_eyes(byte eye0[], byte eye1[])
{
  set_both_eyes(eye0, eye1);
  controlledDelay(longTime);
  clearDisplays();
  set_both_eyes(minus, minus);
  controlledDelay(blinkTime);
  clearDisplays();
}

void custom_blink_eyes(byte frame1[], byte frame2[]) {
  set_both_eyes(frame1, frame1);
  controlledDelay(shortTime);
  clearDisplays();
  set_both_eyes(frame2, frame2);
  controlledDelay(shortTime);
  clearDisplays();
}

void removeEyes()
{
  if (currentValue == "key1") {
    
    remove_both_eyes_slow(X, X);
  }
  if (currentValue == "key2") {
    
    remove_both_eyes_slow(wink_blink, wink_blink);
  }
  if (currentValue == "key4") {
    
    remove_both_eyes_slow(equal, equal);
  }
  if (currentValue == "key5") {
    
    remove_both_eyes_slow(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    
    remove_both_eyes_slow(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    
    remove_both_eyes_slow(at, at);
  }
  if (currentValue == "key8") {
    
    remove_both_eyes_slow(semicolon, semicolon);
  }
  if (currentValue == "key10") {
    
    remove_both_eyes_slow(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    
    remove_both_eyes_slow(question, question);
  }
  if (currentValue == "key12") {
    В¬_В¬
    remove_both_eyes_slow(negation, negation);
  }
  if (currentValue == "key13") {
    
    remove_both_eyes_slow(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    
    remove_both_eyes_slow(tripleDot, tripleDot);
  }
  if (currentValue == "key15") {
    
    remove_both_eyes_slow(wink, wink);
  }
  if (currentValue == "key16") {
    
    remove_both_eyes_slow(wink, wink);
  }
  if (currentValue == "key17") {
    
    remove_both_eyes_slow(O, O);
  }
  if (currentValue == "key18") {
    
    remove_both_eyes_slow(O, smallo);
  }
  if (currentValue == "key19") {
    
    remove_both_eyes_slow(bracket, bracket);
  }
  if (currentValue == "key20") {
    
    remove_both_eyes_slow(star, star);
  }
  if (currentValue == "key21") {
    
    remove_both_eyes_slow(t, t);
  }
  if (currentValue == "key22") {
    
    remove_both_eyes_slow(lenny, lenny);
  }
  if (currentValue == "key23") {
    
    remove_both_eyes_slow(musicNote, musicNote);
  }
  if (currentValue == "key24") {
    
    remove_both_eyes_slow(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    
    remove_both_eyes_slow(leftApostrophe, rightApostrophe);
  }
  if (currentValue == "key26") {
    
    remove_both_eyes_slow(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    
    remove_both_eyes_slow(plus, plus);
  }
  if (currentValue == "key28") {
    
    remove_both_eyes_slow(hashtag, hashtag);
  }
  if (currentValue == "key29") {
    
    remove_both_eyes_slow(u, u);
  }
  if (currentValue == "key30") {
    
    remove_both_eyes_slow(leftArrow2, leftArrow2);
  }
  if (currentValue == "key31") {
    
    remove_both_eyes_slow(rightArrow2, rightArrow2);
  }
  if (currentValue == "key32") {
    
    remove_both_eyes_slow(refresh2, refresh2);
  }
  if (currentValue == "key33") {
    
    remove_both_eyes_slow(charge6, charge6);
  }
  if (currentValue == "key34") {
    
    remove_both_eyes_slow(tick, tick);
  }
  if (currentValue == "key36") {
    
    remove_both_eyes_slow(cute, cute);
  }
  if (currentValue == "key37") {
    
    remove_both_eyes_slow(n, n);
  }
  if (currentValue == "key38") {
    
    remove_both_eyes_slow(hollowSquare, hollowSquare);
  }
  if (currentValue == "key39") {
    
    remove_both_eyes_slow(aries, aries);
  }
  if (currentValue == "key40") {
    
    remove_both_eyes_slow(female, female);
  }
  if (currentValue == "key41") {
    
    remove_both_eyes_slow(male, male);
  }
  if (currentValue == "key42") {
    
    remove_both_eyes_slow(flashingSquare2, flashingSquare2);
  }
  if (currentValue == "key43") {
    
    remove_both_eyes_slow(roundCentre, roundCentre);
  }
  if (currentValue == "key45") {
    
    remove_both_eyes_slow(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    
    remove_both_eyes_slow(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    
    remove_both_eyes_slow(roundFull, roundFull);
  }
}

void changeEyes() {
  if (currentValue == "key1") {
    
    set_both_eyes_slow(X, X);
    generic_eyes(X, X);
  }
  if (currentValue == "key2") {
    
    set_both_eyes_slow(wink, wink);
    shy_eyes();
  }
  if (currentValue == "key3") {
    
    
    wink_eyes();
  }
  if (currentValue == "key4") {
    
    set_both_eyes_slow(equal, equal);
    generic_eyes(equal, equal);
  }
  if (currentValue == "key5") {
    
    set_both_eyes_slow(hashtag, hashtag);
    generic_eyes(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    
    set_both_eyes_slow(rightwink, leftwink);
    generic_eyes(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    
    set_both_eyes_slow(at, at);
    generic_eyes(at, at);
  }
  if (currentValue == "key8") {
    
    set_both_eyes_slow(semicolon, semicolon);
    cry_eyes();
  }
  if (currentValue == "key9") {
    
    sleep_eyes();
  }
  if (currentValue == "key10") {
    
    generic_eyes(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    
    generic_eyes(question, question);
  }
  if (currentValue == "key12") {
    В¬_В¬
    set_both_eyes_slow(negation, negation);
    generic_eyes(negation, negation);
  }
  if (currentValue == "key13") {
    
    set_both_eyes_slow(nineEye, nineEye);
    generic_eyes(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    
    set_both_eyes_slow(tripleDot, tripleDot);
    tripleDot_eyes();
  }
  if (currentValue == "key15") {
    
    set_both_eyes_slow(dollar, dollar);
    money_eyes();
  }
  if (currentValue == "key16") {
    
    set_both_eyes_slow(heart, heart);
    heart_eyes();
  }
  if (currentValue == "key17") {
    
    set_both_eyes_slow(O, O);
    generic_eyes(O, O);
  }
  if (currentValue == "key18") {
    
    set_both_eyes_slow(O, smallo);
    uneven_round_eyes();
  }
  if (currentValue == "key19") {
    
    set_both_eyes_slow(bracket, bracket);
    bracket_eyes();
  }
  if (currentValue == "key20") {
    
    set_both_eyes_slow(star, star);
    generic_eyes(star, star);
  }
  if (currentValue == "key21") {
    
    set_both_eyes_slow(t, t);
    generic_eyes(t, t);
  }
  if (currentValue == "key22") {
    
    set_both_eyes_slow(lenny, lenny);
    generic_eyes(lenny, lenny);
  }
  if (currentValue == "key23") {
    
    set_both_eyes_slow(musicNote, musicNote);
    music_eyes();
  }
  if (currentValue == "key24") {
    
    set_both_eyes_slow(leftQuote, rightQuote);
    generic_eyes(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    
    set_both_eyes_slow(leftApostrophe, rightApostrophe);
    apostrophe_eyes();
  }
  if (currentValue == "key26") {
    
    set_both_eyes_slow(rectangle, rectangle);
    generic_eyes(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    
    set_both_eyes_slow(plus, plus);
    generic_eyes(plus, plus);
  }
  if (currentValue == "key28") {
    
    set_both_eyes_slow(hashtag, hashtag);
    swear_eyes();
  }
  if (currentValue == "key29") {
    
    set_both_eyes_slow(u, u);
    generic_eyes(u, u);
  }
  if (currentValue == "key30") {
    
    set_both_eyes_slow(leftArrow1, leftArrow1);
    custom_blink_eyes(leftArrow2, leftArrow2);
  }
  if (currentValue == "key31") {
    
    set_both_eyes_slow(rightArrow1, rightArrow1);
    custom_blink_eyes(rightArrow2, rightArrow2);
  }
  if (currentValue == "key32") {
    
    set_both_eyes_slow(refresh1, refresh1);
    custom_blink_eyes(refresh1, refresh2);
  }
  if (currentValue == "key33") {
    
    set_both_eyes_slow(charge1, charge1);
    charge_eyes();
  }
  if (currentValue == "key34") {
    
    set_both_eyes_slow(tick, tick);
    generic_eyes(tick, tick);
  }
  if (currentValue == "key35") {
    
    pacman_eyes();
  }
  if (currentValue == "key36") {
    
    set_both_eyes_slow(cute, cute);
    generic_eyes(cute, cute);
  }
  if (currentValue == "key37") {
    
    set_both_eyes_slow(n, n);
    generic_eyes(n, n);
  }
  if (currentValue == "key38") {
    
    set_both_eyes_slow(hollowSquare, hollowSquare);
    generic_eyes(hollowSquare, hollowSquare);
  }
  if (currentValue == "key39") {
    
    set_both_eyes_slow(aries, aries);
    zodiac_eyes();
  }
  if (currentValue == "key40") {
    
    set_both_eyes_slow(female, female);
    generic_eyes(female, female);
  }
  if (currentValue == "key41") {
    
    set_both_eyes_slow(male, male);
    generic_eyes(male, male);
  }
  if (currentValue == "key42") {
    
    set_both_eyes_slow(flashingSquare1, flashingSquare1);
    flashing_square_eyes();
  }
  if (currentValue == "key43") {
    
    set_both_eyes_slow(roundCentre, roundCentre);
    round_dot_eyes();
  }
  if (currentValue == "key44") {
    
    glitch_eyes();
  }
  if (currentValue == "key45") {
    
    set_both_eyes_slow(left_slash, right_slash);
    generic_eyes(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    
    set_both_eyes_slow(right_slash, left_slash);
    generic_eyes(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    
    set_both_eyes_slow(roundFull, roundFull);
    generic_eyes(roundFull, roundFull);
  }
}

void repeatEyes() {
  if (currentValue == "key1") {
    generic_eyes(X, X);
  }
  if (currentValue == "key2") {
    shy_eyes();
  }
  if (currentValue == "key3") {
    wink_eyes();
  }
  if (currentValue == "key4") {
    generic_eyes(equal, equal);
  }
  if (currentValue == "key5") {
    generic_eyes(hashtag, hashtag);
  }
  if (currentValue == "key6") {
    generic_eyes(rightwink, leftwink);
  }
  if (currentValue == "key7") {
    generic_eyes(at, at);
  }
  if (currentValue == "key8") {
    cry_eyes();
  }
  if (currentValue == "key9") {
    sleep_eyes();
  }
  if (currentValue == "key10") {
    generic_eyes(exclamation, exclamation);
  }
  if (currentValue == "key11") {
    generic_eyes(question, question);
  }
  if (currentValue == "key12") {
    generic_eyes(negation, negation);
  }
  if (currentValue == "key13") {
    generic_eyes(nineEye, nineEye);
  }
  if (currentValue == "key14") {
    tripleDot_eyes();
  }
  if (currentValue == "key15") {
    money_eyes();
  }
  if (currentValue == "key16") {
    heart_eyes();
  }
  if (currentValue == "key17") {
    generic_eyes(O, O);
  }
  if (currentValue == "key18") {
    uneven_round_eyes();
  }
  if (currentValue == "key19") {
    bracket_eyes();
  }
  if (currentValue == "key20") {
    generic_eyes(star, star);
  }
  if (currentValue == "key21") {
    generic_eyes(t, t);
  }
  if (currentValue == "key22") {
    generic_eyes(lenny, lenny);
  }
  if (currentValue == "key23") {
    music_eyes();
  }
  if (currentValue == "key24") {
    generic_eyes(leftQuote, rightQuote);
  }
  if (currentValue == "key25") {
    apostrophe_eyes();
  }
  if (currentValue == "key26") {
    generic_eyes(rectangle, rectangle);
  }
  if (currentValue == "key27") {
    generic_eyes(plus, plus);
  }
  if (currentValue == "key28") {
    swear_eyes();
  }
  if (currentValue == "key29") {
    generic_eyes(u, u);
  }
  if (currentValue == "key30") {
    custom_blink_eyes(leftArrow1, leftArrow2);
  }
  if (currentValue == "key31") {
    custom_blink_eyes(rightArrow1, rightArrow2);
  }
  if (currentValue == "key32") {
    custom_blink_eyes(refresh1, refresh2);
  }
  if (currentValue == "key33") {
    charge_eyes();
  }
  if (currentValue == "key34") {
    generic_eyes(tick, tick);
  }
  if (currentValue == "key35") {
    pacman_eyes();
  }
  if (currentValue == "key36") {
    generic_eyes(cute, cute);
  }
  if (currentValue == "key37") {
    generic_eyes(n, n);
  }
  if (currentValue == "key38") {
    generic_eyes(hollowSquare, hollowSquare);
  }
  if (currentValue == "key39") {
    zodiac_eyes();
  }
  if (currentValue == "key40") {
    generic_eyes(female, female);
  }
  if (currentValue == "key41") {
    generic_eyes(male, male);
  }
  if (currentValue == "key42") {
    flashing_square_eyes();
  }
  if (currentValue == "key43") {
    round_dot_eyes();
  }
  if (currentValue == "key44") {
    glitch_eyes();
  }
  if (currentValue == "key45") {
    generic_eyes(left_slash, right_slash);
  }
  if (currentValue == "key46") {
    generic_eyes(right_slash, left_slash);
  }
  if (currentValue == "key47") {
    generic_eyes(roundFull, roundFull);
  }
  if (currentValue == "scrollMessage") {
    if (characterMessage != "") {
      byte byteBuffer1[8];
      byte byteBuffer2[8];
      memcpy_P(byteBuffer1, alphabet + 8 * characterMessage[characterMessagePointer], 8);
      if (characterMessagePointer == 0) {
        scrolling_eye(byteBuffer1, 1);
      }
      ++characterMessagePointer;
      if (characterMessagePointer > characterMessage.length()-1) {
        characterMessagePointer = 0;
        
        memcpy_P(byteBuffer2, alphabet, 8);
      }
      else {
        memcpy_P(byteBuffer2, alphabet + 8 * characterMessage[characterMessagePointer], 8);
      }
      scrolling_both_eyes(byteBuffer1, byteBuffer2);
    }
  }
  if (currentValue == "custom") {
    generic_eyes(customLED, customLED);
  }
}

void customMessage(String message) {
  int count = 0;
  characterMessage = "";
  characterMessagePointer = 0;
  for (char c : message) {
    if (count == maxMessageSize) {
      break;
    }
    if (c >= 32 && c <= 33) {
      c -=32;
      characterMessage += c;
    }
    else if (c == 46) {
      c -= 44;
      characterMessage += c;
    }
    else if (c >= 48 && c <= 57) {
      c -= 45;
      characterMessage += c;
    }
    else if (c >= 65 && c <= 90) {
      c -= 52;
      characterMessage += c;
    }
    else if (c >= 97 && c <= 122) {
      c -= 84;
      characterMessage += c;
    }
    else {
      --count;
    }
    ++count;
  }
  Serial.println("Message" + characterMessage);
  if (characterMessage != "") {
    currentValue = "scrollMessage";
  }
}

boolean inKeySet(String value)
{
  boolean valid = false;
  if (value.substring(0, 3) == "key" && value.substring(3).toInt() <= 47) {
    valid = true;
  }
  return valid;
}

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("wrenchmask");

  led.shutdown(0,false);  
  led.shutdown(1,false);
  
  led.setIntensity(0,maxBrightness);  
  led.setIntensity(1,maxBrightness);

  changeEyes();
}

void loop()
{
  while (SerialBT.available()) {
    data = "";
    char c = SerialBT.read();
    if (c == '(') {
      boolean receivingMessage = true;
      while (receivingMessage) {
        if (SerialBT.available()) {
          c = SerialBT.read();
          if (c == ')') {
            receivingMessage = false;
          }
          else {
            data += c;
          }
        }
        else {
          receivingMessage = false;
        }
      }
    }
    if (data != currentValue && inKeySet(data)) {
      removeEyes();
      if (currentValue != "key44") {
        delay(blinkTime);
      }
      currentValue = data;
      frame = 0;
      changeEyes();
    }
    if (data.substring(0, 6) == "bright") {
      maxBrightness = String(data[6]).toInt();
      led.setIntensity(0,maxBrightness);
      led.setIntensity(1,maxBrightness);
    }
    if (data.substring(0, 7) == "message") {
      customMessage(data.substring(7));
    }
    if (data.substring(0, 5) == "speed") {
      textSpeed = data.substring(5).toInt();
    }
    if (data.substring(0, 3) == "led") {
      for (int i=0; i<8; i++) {
        byte b = data.substring(3+(i*3), 6+(i*3)).toInt();
        customLED[i] = b;
      }
      currentValue = "custom";
    }
  }
  repeatEyes();
  Serial.print(data);
  Serial.print(currentValue);
}
