#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 3

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_GRB + NEO_KHZ800);
int defaultBrightness = 100;
int maxBrightness = 250;
int currentBrightness = 0;
uint32_t JawaColor = strip.Color(255, 127, 0);

boolean randomOn = true;

unsigned long lasttime;
#include <Keypad.h>

const byte ROWS = 3; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'},
  
};
byte rowPins[ROWS] = {12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

char currentState = '0';

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  //Serial.begin(115200);
  //Serial.println("starting..");
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  lasttime = millis();
  randomSeed(analogRead(0));
  
}

void wink()
{

  for(int x=0;x<=maxBrightness;x=x+2)
  {
    //Serial.println(x);
    for(int y=0;y<9;y++)
    {
      currentBrightness = x;
      strip.setBrightness(x);
      strip.setPixelColor(y, JawaColor);
      
    }
    strip.show();
    delay(1);
  }

  for(int x=maxBrightness;x>defaultBrightness;x--)
  {
    //Serial.println(x);
    for(int y=0;y<9;y++)
    {
      currentBrightness = x;
      strip.setBrightness(x);
      strip.setPixelColor(y, JawaColor);
      
    }
    strip.show();
    delay(1);
  }
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void empty()
{


    for(int y=0;y<9;y++)
    {
      //strip.setBrightness(0);
      strip.setPixelColor(y, 0);
      
    }
    strip.show();
    
  
}

void breath(uint8_t wait)
{
  for(int x=20;x<240;x=x+5)
  {
    for(int i=0; i<9; i++)
    {
      strip.setBrightness(x);
      strip.setPixelColor(i, JawaColor);
    }
    strip.show();
    delay(wait);
  }

  for(int x=240;x>20;x=x-5)
  {
    for(int i=0; i<9; i++)
    {
      strip.setBrightness(x);
      strip.setPixelColor(i, JawaColor);
    }
    strip.show();
    delay(wait);
  }

  for(int x=20;x<defaultBrightness;x=x+5)
  {
    for(int i=0; i<9; i++)
    {
      strip.setBrightness(x);
      strip.setPixelColor(i, JawaColor);
    }
    strip.show();
    delay(wait);
  }
  
}

void Side2Side(uint8_t wait) 
{
for(int y=0;y<3;y++)
{  
  for(int i=0; i<3; i++)
  {
    for(uint16_t x=0;x<9;x=x+3)
    {
      strip.setPixelColor(i+x, JawaColor);
    }
    strip.show();
    delay(wait);

    for(uint16_t x=0;x<9;x=x+3)
    {
      //Serial.println(x);
      strip.setPixelColor(i+x, 0);
    }
    //strip.show();
    //delay(wait);
  }
  
  delay(wait);delay(wait);delay(wait);

  for(int i=3;i>0;i--)
  {
    //3,2,1
    for(int x=9;x>0;x=x-3)
    {
      //9,6,3
      int pin = x-i + (i-((3-i)+1)) ;  //2
      strip.setPixelColor(pin, JawaColor);
    }
    
    strip.show();
    delay(wait);

    for(int x=9;x>0;x=x-3)
    {
      //9,6,3
      int pin = x-i + (i-((3-i)+1)) ;  //2
      strip.setPixelColor(pin, 0);
    }

    //strip.show();
    //delay(wait);
  }


}
delay(100);  
  
}



void Side2Side2(uint8_t wait) 
{
for(int y=0;y<3;y++)
{
  for(int i=3;i>0;i--)
  {
    //3,2,1
    for(int x=9;x>0;x=x-3)
    {
      //9,6,3
      int pin = x-i + (i-((3-i)+1)) ;  //2
      strip.setPixelColor(pin, JawaColor);
    }
    
    strip.show();
    delay(wait);

    for(int x=9;x>0;x=x-3)
    {
      //9,6,3
      int pin = x-i + (i-((3-i)+1)) ;  //2
      strip.setPixelColor(pin, 0);
    }
  }

  delay(wait);delay(wait);delay(wait);

  for(int i=0; i<3; i++)
  {
    for(uint16_t x=0;x<9;x=x+3)
    {
      strip.setPixelColor(i+x, JawaColor);
    }
    strip.show();
    delay(wait);

    for(uint16_t x=0;x<9;x=x+3)
    {
      //Serial.println(x);
      strip.setPixelColor(i+x, 0);
    }
  }

}
delay(100);
}


void defaultEyes()
{
  delay(100);
  for(int y=0;y<9;y++)
  {
    strip.setBrightness(defaultBrightness);
    strip.setPixelColor(y, JawaColor);
  }
  strip.show();
}

void spiral()
{
      
  int pinOrder[] = {0, 1, 2, 5, 8,7,6,3};
  int numPins = 8;
  int delayTime = 100;
  for(int y=0;y<3;y++)
  for(int x=0;x<numPins;x++)
  {
    
    strip.setPixelColor(pinOrder[x], JawaColor);
    strip.show();
    delay(delayTime);
    if(x > 0)
    {
      strip.setPixelColor(pinOrder[x-1], JawaColor);
    }
    if(x > 1)
    {
      strip.setPixelColor(pinOrder[x-1], 0);
    }
    if(x == 1)
    {
      strip.setPixelColor(pinOrder[0], 0);
    }

    strip.setPixelColor(pinOrder[numPins-1], 0);
    strip.show();
    delay(delayTime);
    
  }
  
}


void loadup()
{
  int pinOrder[] = {6,7,8,3,4,5,0,1,2};
  for(int x=0;x<3;x++)
  for(int i=0;i<3;i++)
  {
     
      
      int pos = (i*3);
      strip.setPixelColor(pinOrder[pos], JawaColor);
      strip.setPixelColor(pinOrder[pos+1], JawaColor);
      strip.setPixelColor(pinOrder[pos+2], JawaColor);
      strip.show();
      delay(300);
    
  }
  //delay(300);
  empty();
}

void loaddown()
{
  int pinOrder[] = {0,1,2,3,4,5,6,7,8};
  for(int x=0;x<3;x++)
  for(int i=0;i<3;i++)
  {
     
      
      int pos = (i*3);
      strip.setPixelColor(pinOrder[pos], JawaColor);
      strip.setPixelColor(pinOrder[pos+1], JawaColor);
      strip.setPixelColor(pinOrder[pos+2], JawaColor);
      strip.show();
      delay(300);
    
  }
  //delay(300);
  empty();
}

void theaterChase(uint8_t wait) {
  uint8_t c = JawaColor;
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < 9; i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < 9; i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void loop() {
  
  char customKey = customKeypad.getKey();
 
  
  if (customKey){
    //Serial.println(customKey);
    currentState = customKey;
    if(customKey == '1')
    {
      breath(20);
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '0')
    {
      breath(20);
      defaultEyes();
      lasttime = millis();
      randomOn = true;
    }
    if(customKey == '2')
    {
      wink();
      empty();
      wink();
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '3')
    {
      empty();
      Side2Side(100);
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '4')
    {
      empty();
      Side2Side2(100);
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '5')
    {
      empty();
      spiral();      
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '6')
    {
      empty();
      //delay(100);
      loadup();
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }
    if(customKey == '7')
    {
      empty();
      //delay(100);
      loaddown();
      defaultEyes();
      lasttime = millis();
      randomOn = false;
    }

    

    
  }
  
  if((millis() - lasttime) > 5000)
  {
    //Serial.println("One second passed.");
    //Serial.println(millis() - lasttime);
    
    //random(0, 5000);
    if(randomOn == true)
    {
      char t = char(random(1,8)) + '0';
      currentState = t;
      //Serial.println(currentState);
    }
    
    if(currentState == '1')
    {
      breath(20);
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '2')
    {
      wink();
      empty();
      wink();
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '3')
    {
      empty();
      Side2Side(100);
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '4')
    {
      empty();
      Side2Side2(100);
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '5')
    {
      empty();
      spiral();      
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '6')
    {
      empty();
      delay(100);
      loadup();
      defaultEyes();
      lasttime = millis();
    }
    if(currentState == '7')
    {
      empty();
      delay(100);
      loaddown();
      defaultEyes();
      lasttime = millis();
    }

    
  }
  else
  {
    //Serial.println(millis() - lasttime);
  }

}
