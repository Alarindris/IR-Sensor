#ifndef BUTTON_H
#define BUTTON_H

class Button{
	
	bool isEngaged, changeState;
	int delay, onDelay, offDelay, clockMultiplier, pin;
	
	public:
		Button(int, int, int, int);
		void debounce(int);
		void checkInput();
		bool checkState();
		bool isPushed();
};
#endif