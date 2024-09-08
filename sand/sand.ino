const int flameSensorPin = A0;  // Connect to A0 to measure the analog signal
const int threshold = 500;      // Adjust this value based on your readings (higher = more sensitive)

void setup() {
  pinMode(flameSensorPin, INPUT);
  Serial.begin(9600);           // Start serial communication for monitoring
  pinMode(2,1);
}

void loop() {
  int sensorValue = analogRead(flameSensorPin);  // Read the sensor value
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the sensor value is below the threshold (indicating flame detection)
  if (sensorValue < threshold) {
    Serial.println("Flame detected!");
    digitalWrite(2, 1);
  } else {
    digitalWrite(2, 0);
    Serial.println("No flame detected.");
  }

  delay(1000);  // Wait 1 second before the next reading
}

