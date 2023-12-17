#include <DHT11.h>

DHT11 dht11(7);

// #define DHT11_PIN 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
    int temperature = dht11.readTemperature();


    // Check the result of the reading.
    // If there's no error, print the temperature value.
    // If there's an error, print the appropriate error message.
    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT)
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
    }
    else
    {
        Serial.println(DHT11::getErrorString(temperature));
    }

    delay(1000);
    
    int humidity = dht11.readHumidity();

    if (humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT)
    {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }
    else
    {
        Serial.println(DHT11::getErrorString(humidity));
    }
    delay(1000);
}
