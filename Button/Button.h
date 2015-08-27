#ifndef BUTTON_H
#define BUTTON_H

class Button{
    
    bool isEngaged, changeState, safety;
    int pin;
    unsigned long onDelay, offDelay, tempTime;
    
    unsigned long getElapsed();
      
    public:
        Button(long, long, int);
        void debounce(int);
        void checkInput();
        bool checkState();
        bool isPushed();
};
#endif