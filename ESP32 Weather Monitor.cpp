#include <DHT.h>

// DHT sensor settings
#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  Serial.println("ESP32 Weather Monitor");
  Serial.println("---------------------");
}

void loop() {
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if sensor reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Could not read DHT11 sensor!");
    delay(2000);
    return;
  }

  // Display readings
  Serial.println("Weather Data");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("---------------------");

  // Read every 2 seconds
  delay(2000);
}
