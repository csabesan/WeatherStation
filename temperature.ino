#include "dht.h"
#include <LiquidCrystal.h> // Include the regular LiquidCrystal library

#define dht_apin A0 // Analog Pin sensor is connected to

// Initialize the LCD (Pin 12, 11, 5, 4, 3, 2 correspond to RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT; // Initialize the DHT sensor

void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor
  delay(500);  // Delay to let system boot
  Serial.println("DHT11 Humidity & Temperature Sensor\n\n");
  delay(1000); // Wait before accessing the sensor
  
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Weather Station"); // Display a welcome message on the LCD
  delay(2000); // Wait for 2 seconds to show the welcome message
  lcd.clear();  // Clear the screen to make space for the readings
}

void loop() {
  // Read data from the DHT sensor
  DHT.read11(dht_apin); 
  
  // Check if the sensor data is valid
  if (isnan(DHT.humidity) || isnan(DHT.temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.print("Sensor Error!");
    return;
  }

  // Print data to Serial Monitor
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  
  // Display data on the LCD
  lcd.clear();  // Clear previous data on the LCD
  lcd.setCursor(0, 0);  // Set cursor to the first row
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);  // Set cursor to the second row
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print(" %");
  
  delay(5000); // Wait 5 seconds before reading the sensor again
}
