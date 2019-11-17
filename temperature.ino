#include <DHT.h>;
#define DHTPIN 2
#define Relay 3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(Relay, OUTPUT);
}

void loop()
{
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    if (temp >= 26){
      digitalWrite (Relay, HIGH); //LOW Actually
    }
    else{
      digitalWrite (Relay, LOW); //HIGH Actually
    }
    Serial.print(char(248));
    Serial.println(" Celsius");
    delay(30000);
}
