#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTPIN 2    
#define DHTTYPE DHT11  
char ssid[] = "RHUTEC";                        //Nombre WiFi 
char pass[] = "Cloclo**1998";                  //Contraseña WiFi
const char* server = "api.thingspeak.com";     //Servidor ThingSpeak
String apiKey = "T9VMRVYDXWLXXJQV";            //Llave publica ThingSpeak
WiFiClient client; //             

DHT dht(DHTPIN, DHTTYPE);

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
  Serial.begin(115200);
}
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {                             
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(h);
                             postStr +="&field2=";
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
