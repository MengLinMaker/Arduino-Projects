// pin used for LED
int ledPin = 13;
// potentiometer pin
int potPin = A0;
float potVal = 0;

// periodic flashing time
float waitTimeOff = 5000;
// the power number by potentiometer
float waitFactor = 0;
// number used to determine flash time
float waitTimeOn;


void setup() {

  Serial.begin(9600);
  // pin number of LED
  pinMode(ledPin,OUTPUT);
}

void loop() {

  // read potentiometer value
  potVal = analogRead(potPin);
  waitFactor = potVal/1023;
  Serial.println(waitFactor);
  
  if (waitFactor > 0)
  {
    digitalWrite(ledPin,HIGH);

    // function to alter brigtness by altering flash time ratio
    waitTimeOn = pow(waitFactor,2)*waitTimeOff;
    
    delayMicroseconds(waitTimeOn);
    digitalWrite(ledPin,LOW);
    delayMicroseconds(waitTimeOff);
  }
}
