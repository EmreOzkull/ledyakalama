#include <FastLED.h>
#define NUM_LED_STRIP_1 22
#define NUM_LEDS_TOTAL  22
#define BRIGHTNESS  255

#define LED_PIN_A 5
int butonPin = 2;

#define LED_TYPE    WS2812B

CRGB ledsA[NUM_LED_STRIP_1];

int butonDurum;
int i;
int k=0;
int r;
int j;
int n = 100;
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN_A, GRB>(ledsA, NUM_LED_STRIP_1);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(butonPin, INPUT_PULLUP);
  start();
}
void over(){
  for (int j=0;j<15;j++){
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Pink);
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Orange);
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Yellow);
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Green);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Blue);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Purple);;
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
  }
  n =100;
}
void win(){
  n = n-25;
  if(n==25){
    over();
  }
  for (int j=0;j<15;j++){
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Green);
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);;
    FastLED.show();
    delay(100);
  }
  
  start();
}
void lose(){
  for (int j=0;j<15;j++){
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Red);
    FastLED.show();
    delay(100);
    fill_solid(ledsA, NUM_LED_STRIP_1, CRGB::Black);
    FastLED.show();
    delay(100);
  }
  
  loop();
}
void start(){
  r = random(1,NUM_LED_STRIP_1-1);
  loop();
}


void loop() {
  i = 0;
  for (int i = 0; i < NUM_LED_STRIP_1 ; i++){
    butonDurum = digitalRead(butonPin);
    if(i==0){
      if (i==r){
        if (butonDurum == 0){
          if(i==r){
            win();
          }
          else{
            lose();
          }
        } 
        ledsA[i] = CRGB(40,0,60);
        ledsA[NUM_LED_STRIP_1-1] = CRGB::Black;
        FastLED.show();
      }
      else{
        if (butonDurum == 0){
          if(i==r){
            win();
          }
          else{
            lose();
          }
        }
        ledsA[NUM_LED_STRIP_1-1] = CRGB::Black;
        ledsA[i] = CRGB(0,255,0);
        ledsA[r] = CRGB(255,0,0);
        FastLED.show();
    }
    }
    else{
      if (i==r){
        if (butonDurum == 0){
          if(i==r){
            win();
          }
          else{
            lose();
          }
        }
        ledsA[i] = CRGB(40,0,60);
        ledsA[i-1] = CRGB::Black;
        FastLED.show();
      }
      else{
        if (butonDurum == 0){
          if(i==r){
            win();
          }
          else{
            lose();
          }
        }
        ledsA[i] = CRGB(0,255,0);
        ledsA[i-1] = CRGB::Black;
        ledsA[r] = CRGB(255,0,0);
        FastLED.show();
      }
    delay(n);
    
    }
  }
}
