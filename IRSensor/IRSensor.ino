#include <Button.h>
#include <Relay.h>

int LED = 13;
int IR = 2;
int AIR = 3;

int ON_DELAY = 1000;
int OFF_DELAY = 500;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(IR, INPUT);
    pinMode(AIR, OUTPUT);
}

void loop() {
    Button button(ON_DELAY, OFF_DELAY, IR);
    Relay LED(13);
    while(true){
        button.checkInput();
        if(button.checkState()){
            if(button.isPushed()){
                LED.engage();                
            }
            else{
                LED.disengage();
            }
        }
    }
}