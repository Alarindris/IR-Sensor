#define BUTTON_PIN 2
#define ION_PIN 11
#define AIR_PIN 12
#define RELAY_OFFSET 50
#define ON_DELAY 50
#define OFF_DELAY 25
#define INTERVAL 25

void setup() {
  // put your setup code here, to run once:
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