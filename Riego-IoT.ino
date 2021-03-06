#include <ESP8266WiFi.h>
#include <DHT.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define ONE_WIRE_BUS D2
#define pirPin D1
#define sensorPin D6 
#define rainPin D5
#define DHTPIN 2    
#define DHTTYPE DHT11  
char auth[] = "twwgkR7jNi09H6EHM87AGO35dVm4Uu5m";   //Llave Blynk
char ssid[] = "RHUTEC";                        //Nombre WiFi 
char pass[] = "Cloclo**1998";                  //Contraseña WiFi
const char* server = "api.thingspeak.com";     //Servidor ThingSpeak
String apiKey = "T9VMRVYDXWLXXJQV";            //Llave publica ThingSpeak
WiFiClient client; //              

int pirValue;                   
int pinValue;

int sensorState = 0;
int rainState = 0;
int lastState = 0;
int lastRainState = 0;

int sensor=0;

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

const int sensor_pin = A0;

BLYNK_WRITE(V0)
{
 pinValue = param.asInt();    
}

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("No se pudo leer los datos del Sensor DH11");
    return;
  }
   
  Blynk.virtualWrite(V5, h);  //V5 Humedad
  Blynk.virtualWrite(V6, t);  //V6 Temperatura
}
void setup()
{
  Blynk.begin(auth, ssid, pass);
  pinMode(sensorPin, INPUT);
  pinMode(rainPin, INPUT);
  pinMode(pirPin, INPUT);
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
  Blynk.virtualWrite(V2,sensor);
  delay(1000);
}

void getPirValue(void)        //Obtener Datos del Sensor PIR
  {
   pirValue = digitalRead(pirPin);
    if (pirValue) 
     { 
       Serial.println("Movimiento Detectado");
       Blynk.notify("Movimiento Detectado");  
     }
  }

void loop()
{
  Blynk.run(); 
  timer.run(); 
  sendTemps();
  sensorState = digitalRead(sensorPin);
  Serial.println(sensorState);
  
if (sensorState == 1 && lastState == 0) {
  Serial.println("Enviar notificacion, necesita agua");
  Blynk.notify("Riega tus plantas");
  lastState = 1;
  delay(1000);
//Enviar notificación 
    
  } 
  else if (sensorState == 1 && lastState == 1) {
    //No hacer nada, no ha sido regado todavia
  Serial.println("No ha sido regado todavia");
  delay(1000);
  }
  else {
    Serial.println("No necesita agua");
    lastState = 0;
    delay(1000);
  }

  rainState = digitalRead(rainPin);
  Serial.println(rainState);

  if (rainState == 0 && lastRainState == 0) {
  Serial.println("Esta lloviendo!");
  lastRainState = 1;
  delay(1000);
  }
//Enviar notificacion
  else if (rainState == 0 && lastRainState == 1) {
  delay(1000);
  }
  else {
    Serial.println("No esta lloviendo");
    lastRainState = 0;
    delay(1000);
  }
  if (pinValue == HIGH)    
      {
        getPirValue();
      }

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
                             postStr +="&field4=";
                             postStr += String(pinValue);
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
                             Serial.print(" Valor PIR: ");
                             Serial.print(pinValue);
                             Serial.println("%. Enviado a Thingspeak.");
                             
                        }
          client.stop();
 
          Serial.println("Esperando...");
  
  // thingspeak necesita minimo 15 seg de retraso para las actualizaciones
  delay(1000);                        
}
