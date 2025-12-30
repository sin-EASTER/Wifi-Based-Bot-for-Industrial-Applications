
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <Servo.h>

int pos = 20; 
 Servo myservo;  // create servo object to control a servo
const char* ssid = "TP-LINK_1400";
const char* password = "25583731";
/////////////////////////////////////////////////custom pins

uint8_t Pwm1 = 0; //Nodemcu PWM pin 
uint8_t Pwm2 = 12; //Nodemcu PWM pin

//Seven segment pins attachecd with nodemcu pins  
int a0 = 4;  //Gpio-4 of nodemcu esp8266  
int a1 = 5;  //Gpio-5 of nodemcu esp8266    
int a2 = 13;  //Gpio-13 of nodemcu esp8266   
int a3 = 14;  //Gpio-14 of nodemcu esp8266   
//int servo = 15: //servooo

WiFiServer server(80);
 
void setup() {
  myservo.attach(15);
   // myservo.write(0);
  Serial.begin(115200);
  delay(10);
//Declaring l293d control pins as Output
pinMode(a0, OUTPUT);     
pinMode(a1, OUTPUT);     
pinMode(a2, OUTPUT);
pinMode(a3, OUTPUT);    
//pinMode(servo, OUTPUT); 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}



 
void loop()
{                                         
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
/////////////////////////////////////////////////////////////////////////////////direction
 int Ms=0,dir=0,Pw=0;
 // Match the request
 /////////////////////////////////////////////////////////////////////////////////////SERVO
 if (request.indexOf("/tog=3") != -1 )  
 {  
    for ( pos = 20; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);
  }  
  
}
 if (request.indexOf("/start=1") != -1)  {  
  digitalWrite(a0, HIGH); //Start first motor
  digitalWrite(a1, LOW);

  digitalWrite(a2, HIGH); //Start second motor
  digitalWrite(a3, LOW);
  Ms=1;
  dir=1;
}
 if (request.indexOf("/reverse=1") != -1)  {  
  digitalWrite(a1, HIGH); //Start first motor
  digitalWrite(a0, LOW);

  digitalWrite(a3, HIGH); //Start second motor
  digitalWrite(a2, LOW);
  Ms=1;
  dir=1;
}

if (request.indexOf("/stop=1") != -1)  {  
  digitalWrite(a0, LOW); //Stop first motor
  digitalWrite(a1, LOW);

  digitalWrite(a2, LOW); //Stop second motor
  digitalWrite(a3, LOW);
  Ms=0;
}

if (request.indexOf("/tog=1") != -1) /////////////////////////////////LEFT
{
  digitalWrite(a0, HIGH);  //Change First motor rotation direction
 // delay(500); //5 seconds delay
  digitalWrite(a1, LOW);
  
  digitalWrite(a2, LOW); //Change Second motor rotation direction
//  delay(500); //5 seconds delay
  digitalWrite(a3, LOW);
  dir=2;
}



if (request.indexOf("/tog=2") != -1)  ///////////////////////////RIGHT
{
  digitalWrite(a0, LOW);  //Change First motor rotation direction
//  delay(500); //5 seconds delay
  digitalWrite(a1, LOW);
  
  digitalWrite(a2, HIGH); //Change Second motor rotation direction
//  delay(500); //5 seconds delay
  digitalWrite(a3, LOW);
  dir=3;
}


/////////////////////////////////////////////////////////////////////////////////////speed
if (request.indexOf("/Req=2") != -1)  {  
analogWrite(Pwm1, 192);  //Pwm duty cycle 75%
analogWrite(Pwm2, 190);  //Pwm duty cycle 75%
Pw=1;
}
if (request.indexOf("/Req=3") != -1)  { 
analogWrite(Pwm1, 140);  //Pwm duty cycle 50%
analogWrite(Pwm2, 135);  //Pwm duty cycle 50%
Pw=2;
}
if (request.indexOf("/Req=4") != -1)  {  
analogWrite(Pwm1, 75);  //Pwm duty cycle 25%
analogWrite(Pwm2, 75);  //Pwm duty cycle 25%
Pw=3;
}
if (request.indexOf("/Req=1") != -1)  {  
analogWrite(Pwm1, 243);  //Pwm duty cycle 100%
analogWrite(Pwm2, 243);  //Pwm duty cycle 100%
Pw=4;
}

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>"); 


client.println("<style>");
client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f2f2f2; }");
client.println(".banner { background-color: #afb6bd; color: #ad0a7a; padding: 20px; }");
client.println(".banner h1 { font-size: 36px; margin: 0; }");
client.println("</style>");

client.println("<div class=\"banner\">");
client.println("<h1>Nodemcu based WiFi Robot for use in heavy industries or defense</h1>");
client.println("</div><br>");









  
client.println("<style>");
client.println("body { font-family: Arial, sans-serif; text-align: center; background-color: #f2f2f2; }");
client.println("h1 { color: #333; }");
client.println(".button { display: inline-block; margin: 10px; padding: 20px 40px; border: none; border-radius: 30px; font-size: 18px; font-weight: bold; text-decoration: none; text-transform: uppercase; letter-spacing: 1px; transition: background-color 0.3s ease-in-out; }");
client.println(".button-blue { background-color: #007bff; color: #fff; }");
client.println(".button-blue:hover { background-color: #0056b3; }");
client.println(".button-green { background-color: #28a745; color: #fff; }");
client.println(".button-green:hover { background-color: #1e7f37; }");
client.println(".button-red { background-color: #dc3545; color: #fff; }");
client.println(".button-red:hover { background-color: #a71d2a; }");
client.println(".button-yellow { background-color: #ffc107; color: #333; }");
client.println(".button-yellow:hover { background-color: #d39e00; }");
client.println("</style>");



client.println("<a href=\"/start=1\" class=\"button button-green\">Start Motor</a>");
client.println("<a href=\"/reverse=1\" class=\"button button-green\">Reverse Motor</a><br><br>");

client.println("<a href=\"/tog=1\" class=\"button button-blue\">Left Direction</a>");
client.println("<a href=\"/tog=2\" class=\"button button-blue\">Right Direction</a><br><br>");

client.println("<a href=\"/Req=1\" class=\"button button-yellow\">Duty Cycle 100%</a>");
client.println("<a href=\"/Req=2\" class=\"button button-yellow\">Duty Cycle 75%</a><br>");
client.println("<a href=\"/Req=3\" class=\"button button-yellow\">Duty Cycle 50%</a>");
client.println("<a href=\"/Req=4\" class=\"button button-yellow\">Duty Cycle 25%</a><br><br>");

client.println("<a href=\"/stop=1\" class=\"button button-red\">Stop Motor</a>");
client.println("<a href=\"/tog=3\" class=\"button button-green\">DROP</a><br><br>");

  if(Ms==1){
    client.println("Motor Powered Working<br/>" );
    }
    else
    client.println("Motor at Halt<br/>" );

  if(dir==1){
    client.println("Motor rotating in forward direction<br/>" );
    }
    else
    client.println("Motor rotating in backward direction<br/>" );
    if(dir==2){
    client.println("Motor rotating in left direction<br/>" );
    }
    if(dir==3){
    client.println("Motor rotating in right direction<br/>" );
    }
/////////////////////////////////////////////////////////////////////////////////////////////speed 
switch(Pw){
      case 1:
        client.println("Pwm duty cycle 75%<br/>" );
        break;
      case 2:
        client.println("Pwm duty cycle 50%<br/>" );
        break;  
      case 3:
        client.println("Pwm duty cycle 25%<br/>" );
        break; 
         case 4:
        client.println("Pwm duty cycle 100%<br/>" );
        break; 
      default:
        client.println("Pwm duty cycle 100%<br/>" );
  }
  
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
