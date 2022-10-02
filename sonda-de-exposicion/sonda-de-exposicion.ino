// Código destinado a la sonda de exposición (gas, humedad, temperatura, distancia, bluetooth)

#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>

SoftwareSerial miBT(10, 11);

int GAS;
int PINDHT = 4;
int TEMPERATURA;
int HUMEDAD;
const int Trigger = 2;   
const int Echo = 3;   


DHT dht (PINDHT, DHT11);

void setup() {
  Serial.begin (9600);
  miBT.begin(38400);
  dht.begin ();
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  digitalWrite(Trigger, LOW);
}

void loop() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  long t; 
  long DISTANCIA; 

  GAS = analogRead(A0);

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  DISTANCIA = t/59;

  miBT.print(TEMPERATURA);
  miBT.print("-");  
  miBT.print(HUMEDAD);
  miBT.print("-");
  miBT.print(GAS);
  miBT.print("-");
  miBT.print(DISTANCIA);
  miBT.println("-");
  
  delay(500);
}

// Fuentes: 
// https://www.youtube.com/watch?v=1U2aCtLhS4o
// https://www.youtube.com/watch?v=OO7vKKuJ9a0
// https://www.youtube.com/watch?v=kSl8SUb5L9A&t=319s
// https://www.tinkercad.com/things/gobHZD0y40J
// https://www.luisllamas.es/arduino-detector-gas-mq/
// https://naylampmechatronics.com/blog/42_tutorial-sensores-de-gas-mq2-mq3-mq7-y-mq135.html
// https://programarfacil.com/blog/arduino-blog/sensor-dht11-temperatura-humedad-arduino/
// https://www.youtube.com/watch?v=1-ZyM0dGCY8&t=456s
// https://www.youtube.com/watch?v=LtDz15h0c9w