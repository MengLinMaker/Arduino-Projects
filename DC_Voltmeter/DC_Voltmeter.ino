/*
DC Voltmeter 
An Arduino DVM based on voltage divider concept
T.K.Hareendran - Modified
*/

int analogInput = 0; // Pin used for detection + Ground pin
float vout = 0.0;
float vin = 0.0;
float R1 = -1; // Resistance of R1 (will be changed later)
float R2 = -1; // Resistance of R2 (will be changed later)
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   Serial.begin(9600);
   while (!Serial) {
      ; // wait for serial port to connect
   }
   Serial.println("DC VOLTMETER");
   Serial.println("Please specify a resistance value for R1: ");
   while (R1 < 0)
   {
      R1 = Serial.parseFloat();
      Serial.println("Please specify a valid resistance value for R1: ");
   }
      Serial.println("Please specify a resistance value for R2: ");
   while (R2 < 0)
   {
      Serial.println("Please specify a valid resistance value for R2: ");
      R2 = Serial.parseFloat();
   }
   
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
} 
Serial.println("INPUT V= ");
Serial.print(vin);
delay(500);
}
