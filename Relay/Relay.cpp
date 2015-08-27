#include "Relay.h"
#include <Arduino.h>

Relay::Relay(int p){
	pin = p;
	isEngaged = false;
	pinMode(pin, OUTPUT);
}

void Relay::engage(){
	isEngaged = true;
	digitalWrite(pin, HIGH);
}

void Relay::disengage(){
	isEngaged = false;
	digitalWrite(pin, LOW);
}

void Relay::toggle(){
	if(isEngaged){
		digitalWrite(pin, LOW);
	}
	else{
		digitalWrite(pin, HIGH);
	}
	isEngaged = !isEngaged;
}