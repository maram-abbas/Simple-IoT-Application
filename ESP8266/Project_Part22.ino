#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "Embedded Project";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

bool LEDstatus = LOW;

char choice = '\0';

void setup() {
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/ledon", handle_ledon);
  server.on("/ledoff", handle_ledoff);
  server.onNotFound(handle_NotFound);
  
  server.begin();
}
void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  LEDstatus = LOW;
  Serial.print('3');
  server.send(200, "text/html", SendHTML(LEDstatus)); 
  delay(1000);
}

void handle_ledon() {
  LEDstatus = HIGH;
  Serial.print('2');
  server.send(200, "text/html", SendHTML(LEDstatus));
  delay(1000);
}

void handle_ledoff() {
  LEDstatus = LOW;
  Serial.print('3');
  server.send(200, "text/html", SendHTML(LEDstatus));
  delay(1000); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t ledstat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Embedded Project</h1>\n";
  ptr +="<h3>Demo</h3>\n";
  
   if(ledstat == HIGH)
  {ptr +="<p>LED Status: ON</p><a class=\"button button-off\" href=\"/ledoff\">OFF</a>\n";}
  else
  {ptr +="<p>LED Status: OFF</p><a class=\"button button-on\" href=\"/ledon\">ON</a>\n";}


  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
