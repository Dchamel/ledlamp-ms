const int LED=9; 
const int BT=A5; 
boolean alreadyoff = true;

void turnon(){
  if (alreadyoff) {
  Serial.println("TurnON !");
  for (int i=0; i<256; i++) { // Start Turning ON
    analogWrite (LED,i);
    delay(10);
    alreadyoff=false;}
  }
} 
void turnoff(){
  if (!alreadyoff) {
  Serial.println("TurnOFF !");
  for (int i=255; i>=0; i--) { // Turning  OFF
    analogWrite (LED,i);
    delay(10);
    alreadyoff=true;}
  }
}

void setup() {
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
  pinMode (BT, INPUT_PULLUP);
 
}

void loop() {
  Serial.println(!digitalRead(BT));
  if (!digitalRead(BT)==1) {
    turnon();
  } else turnoff();
}