#define BUTTON_PIN 2
#define ION_PIN 11
#define AIR_PIN 12

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(ION_PIN, OUTPUT);
  pinMode(AIR_PIN, OUTPUT);
}

void loop() {
  if(digitalRead(BUTTON_PIN)){
    digitalWrite(ION_PIN, HIGH);
    digitalWrite(AIR_PIN, HIGH);
  }else{
    digitalWrite(ION_PIN, LOW);
    digitalWrite(AIR_PIN, LOW);
  }
}