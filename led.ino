const int LED=9; 
const int MS=2; // Movement Sensor
unsigned long worktime = 30 * 1000; // 30 sec
boolean alreadyoff = true;
boolean state = false;
unsigned long startmillis=0;

void movestate() {
  state = true;
}

void turnon(){

if (alreadyoff) {
    Serial.println("TurnON !");
    Serial.println("Movement Detected !"); 
    for (int i=0; i<256; i++) { // Start Turning ON
    analogWrite (LED,i);
    delay(30);
    alreadyoff=false;}
    startmillis=millis(); // Save Seconds when LED fully ON
  } 
  else {
    if (millis () - startmillis >= worktime) {  //Time NOW - Time when LED was ON
      Serial.println("TurnOFF !");
        for (int i=255; i>=0; i--) { // Turning  OFF
        analogWrite (LED,i);
        delay(50);}
      state=false;
      alreadyoff=true;
    } 
    else Serial.println("Just waiting...");
  }    
}  

void setup() {
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
  pinMode (MS, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MS), movestate, RISING);
}

void loop() {
  
if (state) {
  turnon();
}
  else Serial.println("All Still...");
}