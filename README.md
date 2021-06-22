# ICO-H5
Avances del Proyecto de Riego para la materia de Internet de las Cosas
Guia de proyecto 

Materiales 
Hardware
- Node MCU
- Sensor DHT11
- Sensor YL69
- Sensor PIR
- Protoboard
- Jumpers
- Cable tipo B
- Relay
- Motor Sumergible
Software 
- IDE Arduino 
- ThingSpeak

Procedimiento
Conseguir todos los materiales necesarios
Descargar el ID de Arduino para realizar la programacion 

![image](https://user-images.githubusercontent.com/45986551/122448886-3c9c5880-cf73-11eb-84bf-5a794d30c3d8.png)

Ir a la pagina de ThingSpeak

![image](https://user-images.githubusercontent.com/45986551/122449041-6c4b6080-cf73-11eb-9173-ceb39a87c2cc.png)

Crear cuenta en ThingSpeak e iniciar sesion

![image](https://user-images.githubusercontent.com/45986551/122847664-27f2f400-d2d6-11eb-8fa0-afd4be755f20.png)

Realizar un Esquema de maquetación del Circuito

![image](https://user-images.githubusercontent.com/45986551/122698773-ff0b2a00-d215-11eb-8f15-bffc0224f5eb.png)

Conectar todos los componentes en el Protoboard
Programar el codigo para la adquisicion de datos en tiempo real a atraves de la plataforma ThingSpeak y Blynk 
Crear un canal en ThingSpeak 

![image](https://user-images.githubusercontent.com/45986551/122847760-4822b300-d2d6-11eb-9abe-6e2312a28e16.png)

Configurar el canal con las variables (Humedad del Aire y Temperatura del Aire, Humedad del suelo, Sensor de movimiento ) y los campos necesarios 

![image](https://user-images.githubusercontent.com/45986551/122694038-222fdc80-d20a-11eb-8f52-d12ea49fc9c2.png)

Descargar Blynk del Play Store e importar las Librerias en Arduino

![image](https://user-images.githubusercontent.com/45986551/122847873-7c966f00-d2d6-11eb-843a-fa87166cd4ee.png)

Crear un nuevo proyecto en Blynk y escoger NODEMCU y el tipo de conexion Wifi 
Enviar Email o Copiar la llave para el codigo en Arduino

![image](https://user-images.githubusercontent.com/45986551/122848038-c717eb80-d2d6-11eb-87b2-4c1adabea5fc.png)

Realizar las configuraciones en Blynk 

![image](https://user-images.githubusercontent.com/45986551/122848097-e282f680-d2d6-11eb-9859-6ae59d92a999.png)
![image](https://user-images.githubusercontent.com/45986551/122848124-e9116e00-d2d6-11eb-9ac7-64c677dc291b.png)

Muestreo de datos en Blynk 

![image](https://user-images.githubusercontent.com/45986551/122848146-f75f8a00-d2d6-11eb-9d1a-82c9640f57e8.png)

Alerta de movimiento 

![image](https://user-images.githubusercontent.com/45986551/122848207-13632b80-d2d7-11eb-9c1b-9468a024a79d.png)

Alerta de Riego

![image](https://user-images.githubusercontent.com/45986551/122848212-18c07600-d2d7-11eb-9652-6114eddd4e13.png)






