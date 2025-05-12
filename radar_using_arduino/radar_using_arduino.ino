#include <Servo.h> 

// Define pins for Ultrasonic sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for duration and distance
long duration;
int distance;
Servo myServo; // Servo object to control the motor

void setup() {
  pinMode(trigPin, OUTPUT); // Set trigPin as OUTPUT
  pinMode(echoPin, INPUT); // Set echoPin as INPUT
  Serial.begin(9600); // Start serial communication
  myServo.attach(12); // Attach the servo motor to pin 12
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int i = 0; i <= 180; i++) {
    myServo.write(i); // Move servo to 'i' degrees
    delay(30); // Small delay for smooth movement
    distance = calculateDistance(); // Get distance for current servo position

    // Send angle and distance data to serial monitor
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    delay(10); // Add a small delay to prevent overload in serial output
  }

  // Sweep back from 180 to 0 degrees
  for (int i = 180; i >= 0; i--) {
    myServo.write(i); // Move servo back to 'i' degrees
    delay(30); // Small delay for smooth movement
    distance = calculateDistance(); // Get distance for current servo position

    // Send angle and distance data to serial monitor
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    delay(10); // Add a small delay to prevent overload in serial output
  }
}

// Function to calculate the distance measured by the Ultrasonic sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); // Wait for a short time before sending pulse
  
  digitalWrite(trigPin, HIGH); // Send the pulse
  delayMicroseconds(10); // Keep the pulse HIGH for 10 microseconds
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); // Read the echo pulse duration
  distance = duration * 0.034 / 2; // Calculate the distance in cm
  return distance; // Return the calculated distance
}
