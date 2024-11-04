// INPUT = 0; OUTPUT = 1; LOW = 0; HIGH = 1;
int echoPin = 3;
int trigPin = 2;
int buzzer = 4;
int led1 = 5;
int led2 = 6;
float distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.println("Distance Measure Program: ");
}


void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance  = pulseIn(echoPin, HIGH) * 0.034 / 2;
  Serial.println("Distance: " + String(distance) + " cm");
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(buzzer, LOW);

  if(distance <= 10){
    Serial.println("very close");
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH);
  }else if(distance <= 50){
    Serial.println("Near Range");
    digitalWrite(led1, HIGH);
  }else{
    Serial.println("Far Range");
  }

  delay(500);
}
