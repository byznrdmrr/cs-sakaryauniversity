
#include <ESP8266WiFi.h>

const char* ssid = "Beyza's Iphone";  
const char* password = "byznrdmr";  
char server[] = "mail.smtp2go.com";  
const int flame = D0; 
const int buzz = D1;
WiFiClient Client;              //define wifi client as client

void setup() {

  pinMode(flame,INPUT);
  pinMode(buzz,OUTPUT);

  Serial.begin(115200);         
  Serial.println("");
  Serial.print("Connecting To: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);     

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {

  int t = digitalRead(flame);

  Serial.println(t);
   if (t==0) {           
  digitalWrite(buzz,HIGH);
    sendEmail();
    Serial.print("Mail sent to:"); 
    Serial.println("The recipient");
    Serial.println("");
  }
digitalWrite(buzz,LOW);
}

byte sendEmail()
{
  if (Client.connect(server, 2525) == 1)        // connect to smtp server with port address 2525
  {
    Serial.println(F("connected to server"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp())         // if connection failed return now
    return 0;
  //
  Serial.println(F("Sending EHLO"));
  Client.println("EHLO www.example.com");      
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  Client.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending User"));
  Client.println("Ynl6bnJyZG1yQGdtYWlsLmNvbQ=="); //base64, ASCII encoded SMTP Username   
  if (!emailResp()) 
    return 0;

  Serial.println(F("Sending Password"));
  Client.println("MGpIQUZ5S3BDTml0");   //base64, ASCII encoded SMTP Password    
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending From"));
    Client.println(F("MAIL From: sender@xyz.com"));       
  if (!emailResp())  
    return 0;
  // change to recipient address
  Serial.println(F("Sending To"));
  Client.println(F("RCPT To: receiver@xyz.com"));    
  
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending DATA"));
  Client.println(F("DATA"));
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending email"));
  Client.println(F("To: receiver@xyz.com "));                
  Client.println(F("From: sender@xyz.com"));                 
  Client.println(F("Subject: Fire Alarm\r\n"));
  Client.println(F("Attention: Fire Detected.\n"));
  Client.println(F("."));
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending QUIT"));
  Client.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  Client.stop();
  Serial.println(F("disconnected"));
  return 1;
}

byte emailResp()
{
  byte responseCode;
  byte readByte;
  int loopCount = 0;

  while (!Client.available()) 
  {
    delay(1);
    loopCount++;
    // Wait for 20 seconds and if nothing is received, stop.
    if (loopCount > 20000) 
    {
      Client.stop();
      Serial.println(F("\r\nTimeout"));
      return 0;
    }
  }

  responseCode = Client.peek();
  while (Client.available())
  {
    readByte = Client.read();
    Serial.write(readByte);
  }

  if (responseCode >= '4')
  {
    //  efail();
    return 0;
  }
  return 1;
}
