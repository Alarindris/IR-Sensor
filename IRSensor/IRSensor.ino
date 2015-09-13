#include <Bounce2.h>

#define BUTTON_PIN 2
#define ION_PIN 13
#define AIR_PIN 12
#define RELAY_OFFSET 50
#define ON_DELAY 1000
#define OFF_DELAY 500
#define INTERVAL 25

Bounce debouncer = Bounce(); 

void setup() {
    pinMode(BUTTON_PIN,INPUT_PULLUP);
    debouncer.attach(BUTTON_PIN);
    debouncer.interval(INTERVAL);
    pinMode(ION_PIN, OUTPUT);
    pinMode(AIR_PIN, OUTPUT);
}
 
void loop() {
    if(debouncer.update()){
        bool value = debouncer.read();
        digitalWrite(AIR_PIN, !value);
        delay(RELAY_OFFSET);
        digitalWrite(ION_PIN, !value);
        delay(ON_DELAY - RELAY_OFFSET);
    }
}
