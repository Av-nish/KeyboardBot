#include <ESP8266WiFi.h>
#include <WiFiClient.h>
WiFiClient client;


const uint16_t port = 1111;
const char *host = "192.168.137.1";
char command;

const int n = 4;
int m[n] = {14,12,15,13};


void setup()
{   
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    for(int i = 0; i < n; i++)
        pinMode(m[i], OUTPUT);

    for(int i = 0; i < n; i++)
      digitalWrite(m[i], LOW);

    Serial.begin(9600);
    Serial.println("Connecting...\n");
    WiFi.mode(WIFI_STA);
    WiFi.begin("WIFI", "123456789"); 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        Serial.print(" .");
    }
    Serial.println("Wifi Connected !!");
    digitalWrite(LED_BUILTIN, HIGH);

}

void loop()
{
    Serial.println(1);
    if (!client.connect(host, port))
    {
        Serial.println("Connection to host failed");
        return;
    }
    Serial.println(2);
    
    delay(40);
    for(int i = 0; client.available() > 0; i++)
    {
        command = client.read();
        Serial.print(command);
    } 

    if (command = 'w')
    {
      forward();
    }   
    if (command = 's')
    {
      backward();
    } 
    if (command = 'a')
    {
      left();
    }   
    if (command = 'd')
    {
      right();
    }  
     
    
    client.stop();
   
}

void forward()
{
  digitalWrite(14,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(15,LOW);
}

void backward()
{
  digitalWrite(14,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(15,HIGH);
}

void left()
{
  digitalWrite(14,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(15,HIGH);

}
void right()
{
  digitalWrite(14,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(15,LOW); 

}
