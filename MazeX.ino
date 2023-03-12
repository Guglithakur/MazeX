int leftMotor = 5; // Attach left motor to pin 5
int rightMotor = 7; // Attach right motor to pin 6
int sensorLeft = A0; // Attach left sensor to analog pin A0
int sensorRight = A1; // Attach right sensor to analog pin A1
int sensorThreshold = 500; // Set sensor threshold value

void setup() {
  pinMode(leftMotor, OUTPUT); // Set left motor as output
  pinMode(rightMotor, OUTPUT); // Set right motor as output
}

void loop() {
  int leftSensorValue = analogRead(sensorLeft); // Read left sensor value
  int rightSensorValue = analogRead(sensorRight); // Read right sensor value
  
  if (leftSensorValue > sensorThreshold && rightSensorValue > sensorThreshold) {
    // If both sensors detect the line, go straight
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH);
  } else if (leftSensorValue < sensorThreshold && rightSensorValue > sensorThreshold) {
    // If only left sensor detects the line, turn left
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
  } else if (leftSensorValue > sensorThreshold && rightSensorValue < sensorThreshold) {
    // If only right sensor detects the line, turn right
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, LOW);
  } else {
    // If both sensors do not detect the line, stop
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
  }
}