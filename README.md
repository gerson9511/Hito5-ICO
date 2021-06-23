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

Alerta de movimiento y Alerta de Riego

![image](https://user-images.githubusercontent.com/45986551/122848207-13632b80-d2d7-11eb-9c1b-9468a024a79d.png)
![image](https://user-images.githubusercontent.com/45986551/122848212-18c07600-d2d7-11eb-9652-6114eddd4e13.png)

Ubicacion de los sensores con Api de google Maps

![image](https://user-images.githubusercontent.com/45986551/123174867-d326b900-d44e-11eb-8675-21e265ba9378.png)

Video de YouTube en ThingSpeak https://www.youtube.com/watch?v=RDdttJ80TDU

![image](https://user-images.githubusercontent.com/45986551/123175724-3c5afc00-d450-11eb-9926-708ecfec8215.png)

Adquisicion de datos de los sensores en ThingSpeak

![image](https://user-images.githubusercontent.com/45986551/123175909-95c32b00-d450-11eb-9749-fbc861351041.png)
![image](https://user-images.githubusercontent.com/45986551/123175936-9f4c9300-d450-11eb-81f3-924c11c4857d.png)
![image](https://user-images.githubusercontent.com/45986551/123175961-a83d6480-d450-11eb-8d65-c342825e9741.png)
![image](https://user-images.githubusercontent.com/45986551/123176040-c86d2380-d450-11eb-9377-1d36233c155f.png)

Control por voz Con IFTTT Google Assistant y Active Voice 

Ingresar a la plataforma de IFTTT crearse una cuenta y loguearse con Google, 

![1](https://user-images.githubusercontent.com/45986551/123176494-8a243400-d451-11eb-9a41-c0025876158e.JPG)
![2](https://user-images.githubusercontent.com/45986551/123176496-8b556100-d451-11eb-8bde-8d9bee31382a.JPG)
![3](https://user-images.githubusercontent.com/45986551/123176501-8d1f2480-d451-11eb-9bba-e23023620590.JPG)
![5](https://user-images.githubusercontent.com/45986551/123176503-8ee8e800-d451-11eb-9822-8e4ce0e6302d.JPG)
![6](https://user-images.githubusercontent.com/45986551/123176510-90b2ab80-d451-11eb-8867-04d448dd0e26.JPG)
![7](https://user-images.githubusercontent.com/45986551/123176514-93150580-d451-11eb-86ba-e7929938cf2c.JPG)
![8](https://user-images.githubusercontent.com/45986551/123176520-94463280-d451-11eb-80a0-d8a33e05e65e.JPG)
![9](https://user-images.githubusercontent.com/45986551/123176522-960ff600-d451-11eb-98fa-9922c5b1dd61.JPG)
![10](https://user-images.githubusercontent.com/45986551/123176528-98725000-d451-11eb-9360-b1fe9769e852.JPG)
![11](https://user-images.githubusercontent.com/45986551/123176534-9c9e6d80-d451-11eb-8dda-43f4b36911ad.JPG)
![12](https://user-images.githubusercontent.com/45986551/123176541-9e683100-d451-11eb-80b4-5afc7d4a1185.JPG)
![13](https://user-images.githubusercontent.com/45986551/123176542-9f995e00-d451-11eb-908d-0b9823223584.JPG)
![14](https://user-images.githubusercontent.com/45986551/123176545-a0ca8b00-d451-11eb-9ca7-0fafb4b4f4b4.JPG)



