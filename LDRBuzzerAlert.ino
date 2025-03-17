const int ledPin=13; // LED is connected to pin 13
const int buzzerPin=12;
const int ldrPin=A0;

void setup () {

  Serial.begin(9600); // Initialize serial communication at 9600 baud rate

  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(ldrPin,INPUT);
}

void loop() {

  int ldrStatus=analogRead(ldrPin);  // Read the analog value from the LDR sensor

  if(ldrStatus>=400) 
  {
    tone(buzzerPin,100);  // Turn on the buzzer with 100 Hz frequency
    digitalWrite(ledPin,HIGH);
    delay(100);

    noTone(buzzerPin);
    digitalWrite(ledPin,LOW);
    delay(100);

    Serial.println("-------ALARM ACTIVATED-------");
  }

  else 
  {
    noTone(buzzerPin);  // Keep the buzzer off
    digitalWrite(ledPin,LOW);
    Serial.println("--------ALARM DEACTIVATED--------");

  }

}