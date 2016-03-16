#define BUTTON_PIN 2
#define ION_PIN 11
#define AIR_PIN 12

//Switch connects pin 2 to ground.

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ION_PIN, OUTPUT);
  pinMode(AIR_PIN, OUTPUT);
}

void loop() {
  //switch on
  if(digitalRead(BUTTON_PIN)){
    digitalWrite(ION_PIN, HIGH);
    digitalWrite(AIR_PIN, HIGH);
  //switch off
  }else{
    digitalWrite(ION_PIN, LOW);
    digitalWrite(AIR_PIN, LOW);
  }
}