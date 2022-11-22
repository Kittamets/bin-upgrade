#include <Servo.h>

Servo servo;

int trig = 1;
int echo = 2;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  servo.attach(8);
  servo.write(0);
  delay(100);
}

void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echo,HIGH);
  Serial.print("Duration : ");
  Serial.println(duration);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 and distance < 15){
    servo.write(150);
    delay(5000);
  }
  else{
    servo.write(0);
  }

}