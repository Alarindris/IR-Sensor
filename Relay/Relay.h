#ifndef RELAY_H
#define RELAY_H

class Relay{
    bool isEngaged;
    int pin;
    public:
        Relay(int); 
        void engage();
        void disengage();
        void toggle();
};

#endif