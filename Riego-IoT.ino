#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTPIN 2    
#define DHTTYPE DHT11  
char ssid[] = "RHUTEC";                        //Nombre WiFi 
char pass[] = "Cloclo**1998";                  //Contraseña WiFi
const char* server = "api.thingspeak.com";     //Servidor ThingSpeak
String apiKey = "T9VMRVYDXWLXXJQV";            //Llave publica ThingSpeak
WiFiClient client; //
                  
int pinValue;                   

int sensorState = 0;
int sensor=0;

DHT dht(DHTPIN, DHTTYPE);

const int sensor_pin = A0;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("No se pudo leer los datos del Sensor DH11");
    return;
  }
}
void setup()
{
  dht.begin();
  
  Serial.println("Conectando a...  ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi conectado");
      
  timer.setInterval(1000L, sendSensor);
  Serial.begin(115200);
}

void sendTemps()
{
  sensor=analogRead(A0); 
  Serial.println(sensor);
  delay(1000);
}

void loop()
{
  sendTemps();
  Serial.println(sensorState);

  delay(100);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {                             
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(h);
                             postStr +="&field2=";
                             postStr += String(t);
                             postStr +="&field3=";
                             postStr += String(sensor);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Humedad del aire: ");
                             Serial.print(h);
                             Serial.print(" Temperatura aire: ");
                             Serial.print(t);
                             Serial.print(" Humedad del Suelo: ");
                             Serial.print(sensor);
                             Serial.println("%. Enviado a Thingspeak.");
                             
                        }
          client.stop();
 
          Serial.println("Esperando...");
  
  // thingspeak necesita minimo 15 seg de retraso para las actualizaciones
  delay(1000);                        
}

                             postStr += String(t);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Humedad del aire: ");
                             Serial.print(h);
                             Serial.print(" Temperatura aire: ");
                             Serial.print(t);
                             Serial.println("%. Enviado a Thingspeak.");                          
                        }
          client.stop();
          Serial.println("Esperando...");
  delay(1000);                        
}
