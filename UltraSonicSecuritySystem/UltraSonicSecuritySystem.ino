/*
 *Programmer:Sullivan Abegg
 *Date:12/12/22
 *Program:Ultrasonic Security  System  
 *
 *Resource:https://create.arduino.cc/projecthub/Krepak/ultrasonic-security-system-3afe13?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1
 */
int trigPin = 2;
int echoPin = 3;
int LEDlampRed = 4;
int LEDlampYellow = 5;
int LEDlampGreen = 6;
int soundBuzzer = 7;
int sound = 1500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundBuzzer, OUTPUT);
}
void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm <= 10 && distanceincm >= 7) {
      digitalWrite(LEDlampGreen, HIGH);
      Serial.println("Getting close proceed with caution");
}
  else {
      digitalWrite(LEDlampGreen, LOW);
  }
  
  if (distanceincm <= 6 && distanceincm >= 4) {
    digitalWrite(LEDlampYellow, HIGH);
    Serial.println("You are very close procceed with caution");
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distanceincm <= 3 && distanceincm >= 1) {
    digitalWrite(LEDlampRed, HIGH);
    tone(soundBuzzer, sound);
    Serial.println("Stop! you are very close");
}
  else {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 10 || distanceincm <= 0){
    Serial.println("All clear Proceed Forward");
    noTone(soundBuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println(" cm");
    
  }
  
  delay(300);
}
