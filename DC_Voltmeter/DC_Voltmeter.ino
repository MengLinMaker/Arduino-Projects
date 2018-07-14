/*
DC Voltmeter 
An Arduino DVM based on voltage divider concept
T.K.Hareendran - Modified by Meng Lin
*/
// Source:
// https://www.allaboutcircuits.com/projects/make-a-digital-voltmeter-using-the-arduino/

int analogInput = A0; // Pin used for detection + Ground pin
float vout = 0.0;
float vin = 0.0;
float R1 = -1; // Resistance of R1 (will be changed later)
float R2 = -1; // Resistance of R2 (will be changed later)
int value = 0;

void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   Serial.println("DC VOLTMETER");

   Serial.print("Please specify a valid resistance value for R1: ");
   while (R1 < 0)
   {
      while (Serial.available()==0) {}
      R1 = Serial.parseFloat();
   }  
   Serial.println(R1);

   Serial.print("Please specify a valid resistance value for R2: ");
   while (R2 < 0)
   {
      while (Serial.available()==0) {}
      R2 = Serial.parseFloat();
   }
   Serial.println(R2);
   Serial.println();
}

void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   // the voltage entering the arduino
   vout = (value * 5.0) / 1024.0;
   // calculated voltage
   vin = vout / (R1/(R1+R2)); 

Serial.print("V = ");
Serial.println(vin);
delay(500);
}
