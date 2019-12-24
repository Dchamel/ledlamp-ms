const int LED=9; 
const int MS=2; //Movement Sensor
unsigned long msmillis=0;
boolean msfcheck = false;

void msfunc () {
  msmillis = millis();
  if (msfcheck != true) {
    for (int i=0; i<256; i++) {
      analogWrite (LED,i);
      delay(20);
    }
    Serial.println("Movement Detected !");
    msfcheck = true;
  } 
  else msmillis = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
  pinMode (MS, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MS), msfunc, HIGH);
}

void loop() {
if (msfcheck && (millis()- msmillis > 20000)) {
  Serial.println("All Still...");
  for (int i=255; i>=0; i--) {
    analogWrite (LED,i);
    delay(10);
  }
  msfcheck = false;
  }
}
