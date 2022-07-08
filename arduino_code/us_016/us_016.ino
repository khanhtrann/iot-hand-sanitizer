unsigned int ADCValue;
void setup(){
    Serial.begin(9600);
}
 
void loop(){
 
    ADCValue = analogRead(A0);
    Serial.print("Khoang cach: ");
    Serial.print(ADCValue, DEC);
    Serial.println("mm");
    delay(1000); //delay 1S
}
