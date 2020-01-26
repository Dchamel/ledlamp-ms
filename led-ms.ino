const int LED=9; 
const int MS=2; // Movement Sensor
unsigned long worktime = 10 * 1000; // 10 sec
boolean alreadyoff = true;
boolean state = false;
boolean state_more = false;
unsigned long startmillis=0;

void movestate() {
  state = true;
  state_more = true;  
}

void turnon(){
  if (alreadyoff) {
    Serial.println("TurnON !");
    Serial.println("Movement Detected !"); 
    for (int i=0; i<256; i++) { // Start Turning ON
    analogWrite (LED,i);
    delay(10);
    alreadyoff=false;}
    
  }
  else {
    if (state_more) {
      startmillis=millis(); // Save Seconds when LED fully ON  
      state_more = false;  // Continue countdown
      Serial.println("Timer reseted.");
    }
    else Serial.println("Continue...");
    
    if (millis () - startmillis >= worktime) {  //Time NOW - Time when LED was ON
      Serial.println("TurnOFF !");
      for (int i=255; i>=0; i--) { // Turning  OFF
      analogWrite (LED,i);
      delay(20);
      }
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