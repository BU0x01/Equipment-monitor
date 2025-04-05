#include <Wire.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

// GPS module connection
SoftwareSerial ss(4, 3);
Adafruit_GPS GPS(&ss);

// Motion sensor pin
int motionSensorPin = 7;
int motionStatus = 0;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  ss.begin(9600);
  GPS.begin(9600);

  // Initialize motion sensor
  pinMode(motionSensorPin, INPUT);
}

void loop() {
  // Check GPS data
  GPS.read();
  
  // Get motion sensor status
  motionStatus = digitalRead(motionSensorPin);

  if (GPS.newNMEAreceived()) {
    if (GPS.parse(GPS.lastNMEA())) {
      // Print GPS coordinates
      Serial.print("Latitude: ");
      Serial.print(GPS.latitude, 6);
      Serial.print(" Longitude: ");
      Serial.println(GPS.longitude, 6);
    }
  }

  // Send data (e.g., to a server or cloud)
  sendDataToServer(GPS.latitude, GPS.longitude, motionStatus);

  delay(1000);
}

void sendDataToServer(float latitude, float longitude, int motionStatus) {
  // Example of sending data to a server or cloud service
  // This could use an HTTP request or MQTT protocol
  // For this example, we'll just print it to the Serial Monitor
  
  Serial.print("Sending data to server: ");
  Serial.print("Latitude: ");
  Serial.print(latitude, 6);
  Serial.print(" Longitude: ");
  Serial.print(longitude, 6);
  Serial.print(" Motion status: ");
  Serial.println(motionStatus);
}
