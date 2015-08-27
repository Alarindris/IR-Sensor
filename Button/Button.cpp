#include "Button.h"
#include <Arduino.h>

Button::Button(long on, long off, int p){
	isEngaged = false;
	changeState = false;
    onDelay = on;
	offDelay = off;
	pin = p;
}

unsigned long Button::getElapsed(){
    return millis() - tempTime;
}

void Button::debounce(int level){
	tempTime = millis();
    unsigned long time;
    unsigned long DELAY;
    
	if(level == 0x1){
		DELAY = offDelay;
	}
	else{
		DELAY = onDelay;
	}
    time = millis();
    
	while((millis() - time) < DELAY){
		delay(1);
        if(digitalRead(pin) == level){
			changeState = false;
            //tempTime = millis();
			break;
		}
		else{
        
			changeState = true;
		}
	}
}

void Button::checkInput(){
  	if(digitalRead(pin) == LOW && !isEngaged){		
        if(getElapsed() < offDelay){
            debounce(0x1);
        }
        else{
            changeState = true;
        }
  	}	
    if(digitalRead(pin) == HIGH && isEngaged){
        debounce(0x0);
    }	
}

bool Button::checkState(){
	bool result;
	if(changeState){
        result = true;
        tempTime = millis();
		isEngaged = !isEngaged;
		changeState = false;
	}
	else{
		result = false;
	}
	return result;
}

bool Button::isPushed(){
	return isEngaged;
}