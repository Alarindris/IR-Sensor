#include <Bounce2.h>

#define BUTTON_PIN 2
#define ION_PIN 13
#define AIR_PIN 12
#define RELAY_OFFSET 50
#define ON_DELAY 1000
#define OFF_DELAY 500

Bounce debouncer = Bounce(); 

void setup() {
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(25); // interval in ms
  pinMode(ION_PIN, OUTPUT);
  pinMode(AIR_PIN, OUTPUT);

}
 
void loop() {
  int value;
  int prevVal;
  
  while(true){
    debouncer.update();
    value = debouncer.read();
    if(value != prevVal){
      if ( value == LOW ) {
        digitalWrite(AIR_PIN, HIGH);
        delay(RELAY_OFFSET);
        digitalWrite(ION_PIN, HIGH);
        delay(ON_DELAY - RELAY_OFFSET);
      } 
      else {
        digitalWrite(ION_PIN, LOW);
        delay(RELAY_OFFSET);
        digitalWrite(AIR_PIN, LOW);
        delay(OFF_DELAY - RELAY_OFFSET);
      }
    }
    prevVal = value;
  }
}

