#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>

// Replace with your Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Replace with your Blynk authentication token
const char* authToken = "YOUR_BLYNK_AUTH_TOKEN";

// Define pins
#define SOIL_MOISTURE_PIN A0
#define DHT_PIN 4
#define BUZZER_PIN 5
#define RED_LED_PIN 6
#define GREEN_LED_PIN 7

// Initialize sensors
DHT dht(DHT_PIN, DHT22);
BH1750 lightMeter;

// Thresholds for alerts
const int moistureThreshold = 30; // Adjust based on soil type
const float tempThreshold = 30.0; // Maximum temperature
const float humidityThreshold = 40.0; // Minimum humidity
const float lightThreshold = 500; // Minimum light intensity (lux)

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize sensors
  dht.begin();
  lightMeter.begin();

  // Set pin modes
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Turn off buzzer and LEDs initially
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH); // Green LED indicates normal condition

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wi-Fi connected");

  // Initialize Blynk
  Blynk.begin(authToken, ssid, password);
}

void loop() {
  // Read sensor data
  int moisture = map(analogRead(SOIL_MOISTURE_PIN), 0, 4095, 100, 0); // Convert to percentage
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float lightIntensity = lightMeter.readLightLevel();

  // Print data to Serial Monitor
  Serial.print("Moisture: "); Serial.print(moisture); Serial.println(" %");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Light Intensity: "); Serial.print(lightIntensity); Serial.println(" lux");

  // Send data to Blynk
  Blynk.virtualWrite(V1, moisture);
  Blynk.virtualWrite(V2, temperature);
  Blynk.virtualWrite(V3, humidity);
  Blynk.virtualWrite(V4, lightIntensity);

  // Check thresholds and trigger alerts
  bool alert = false;
  if (moisture < moistureThreshold || temperature > tempThreshold || humidity < humidityThreshold || lightIntensity < lightThreshold) {
    alert = true;
  }

  if (alert) {
    Serial.println("Alert Triggered!");
    digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer
    digitalWrite(RED_LED_PIN, HIGH); // Turn on red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off green LED
  } else {
    Serial.println("Normal Condition");
    digitalWrite(BUZZER_PIN, LOW); // Deactivate buzzer
    digitalWrite(RED_LED_PIN, LOW); // Turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on green LED
  }

  // Run Blynk
  Blynk.run();

  delay(5000); // Adjust loop speed
}
