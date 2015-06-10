#include <SevSegmentsArray.h>

int lightSensor_1 = 0;
int lightSensor_2 = 5;

int score_1 = 0;
int score_2 = 0;

int ledPin = 13;
int scoreSensor_1;
int scoreSensor_2;

int x = 0;


SevSegmentsArray *seg;

void _initSegment() {
  int pins[2] = {11, 12};
  seg = new SevSegmentsArray(
    pins,
    2,
    new SevSegments(6,9,2,3,4,8,7)
  );
}


void setup() {
  _initSegment();
  
  pinMode(lightSensor_1, INPUT);
  pinMode(lightSensor_2, INPUT);
  
  pinMode( ledPin, OUTPUT );
  digitalWrite(ledPin, HIGH);
  
  scoreSensor_1 = analogRead(lightSensor_1);
  scoreSensor_2 = analogRead(lightSensor_2);
  
  digitalWrite(ledPin, LOW);
  seg->set(0, 0);
  seg->set(1, 0);
}

void loop() {
  int goalSensor_1 = analogRead(lightSensor_1);
  int goalSensor_2 = analogRead(lightSensor_2);
  
  if(x > 0) {
    x--;
  }
  else {
    if((scoreSensor_1-goalSensor_1) > 15){
      x = 50;
      score_1++;
      seg->set(0, score_1);
      digitalWrite(ledPin, HIGH);
    }
    
    if((scoreSensor_2-goalSensor_2) > 15){
      x = 50;
      score_2++;
      seg->set(1, score_2);
      digitalWrite(ledPin, HIGH);
    }
  }
  seg->update();
  delay(5);
}
