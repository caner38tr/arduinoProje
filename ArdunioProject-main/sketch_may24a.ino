const int trigPin = 2;
const int echoPin = 3;
const int yellowLEDPin = 7;
const int redLEDPin = 8;
const int greenLEDPin = 9;
const int obstacleDistance = 15; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  Serial.begin(9600); 
  digitalWrite(greenLEDPin, HIGH); 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance < obstacleDistance) { 
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    delay(3000);
    digitalWrite(yellowLEDPin, LOW); 
    digitalWrite(redLEDPin, HIGH);
    delay(5000); 
    digitalWrite(redLEDPin, LOW); 
    digitalWrite(yellowLEDPin, HIGH); 
    delay(3000); 
    digitalWrite(yellowLEDPin, LOW); 
    
  } else { 
    digitalWrite(redLEDPin, LOW); 
    digitalWrite(yellowLEDPin, LOW); 
    digitalWrite(greenLEDPin, HIGH); 
  }
  delay(100); 
}
