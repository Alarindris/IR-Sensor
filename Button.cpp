#include "Button.h"
#include <Arduino.h>

Button::Button(int on, int off, int clock, int p){
	isEngaged = false;
	changeState = false;
	onDelay = on;
	offDelay = off;
	clockMultiplier = clock;
	pin = p;
}

void Button::debounce(int level){
	unsigned long time = millis();
    int DELAY;
    
	if(level == 0x0){
		DELAY = onDelay;
	}
	else{
		DELAY = offDelay;
	}
	for(long i = 0; i < (long)(DELAY * clockMultiplier); i++){
		if(digitalRead(pin) == level){
			changeState = false;
			break;
		}
		else{
			changeState = true;
		}
	}
	if(millis() - time < DELAY){
		delay(DELAY - (millis() - time));
	}
}

void Button::checkInput(){
	if(digitalRead(pin) == HIGH && isEngaged){
		debounce(0x0);
  	}
  	if(digitalRead(pin) == LOW && !isEngaged){
		debounce(0x1);
  	}	
}

bool Button::checkState(){
	bool result;
	if(changeState){
		result = true;
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