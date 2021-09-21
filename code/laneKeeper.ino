
#define trigPin 12
#define echoPin 13

#include<Servo.h>
Servo Myservo;
int pos;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(8, OUTPUT);
  
  
  Myservo.attach(3);
  Myservo.write(pos);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 10 || distance <= 2){
    Serial.println("Out of range"); // Serial Communication
  }
  else {
    Serial.print(distance); // Serial Communication  
    Serial.println(" cm"); // Serial Communication

    
  }
  delay(500);


  if (distance <= 5) {
    for(pos=0;pos<=180;pos++){
      Myservo.write(pos);
      delay(15);
      } 
  }

  // flashing Street Lights
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
}
