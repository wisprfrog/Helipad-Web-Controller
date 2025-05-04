#include <WiFi.h>
#include "webpage.h" // <-- Include your webpage

const char *ssid = "welim";
const char *password = "wilywily";

WiFiServer server(80);

String header;
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";
String output6State = "off";

const int output1 = 4;  // GPIO 4
const int output2 = 5;  // GPIO 5
const int output3 = 12; // GPIO 12
const int output4 = 13; // GPIO 13
const int output5 = 14; // GPIO 14
const int output6 = 15; // GPIO 15

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

String processor(String page)
{
  page.replace("%STATE1%", output1State);
  page.replace("%STATE2%", output2State);
  page.replace("%STATE3%", output3State);
  page.replace("%STATE4%", output4State);
  page.replace("%STATE5%", output5State);
  page.replace("%STATE6%", output6State);

  page.replace("%BUTTON1%", output1State == "off" ? "<p>
    <a href=\"/1/on\"><button class=\"button\">ON</button></a>
    </p>" : "<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
  page.replace("%BUTTON2%", output2State == "off" ? "<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>" : "<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
  page.replace("%BUTTON3%", output3State == "off" ? "<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>" : "<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
  page.replace("%BUTTON4%", output4State == "off" ? "<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>" : "<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
  page.replace("%BUTTON5%", output5State == "off" ? "<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>" : "<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
  page.replace("%BUTTON6%", output6State == "off" ? "<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>" : "<p><a href=\"/6/off\"><button class=\"button button2\">OFF</button></a></p>");

  return page;
}

void setup()
{
  Serial.begin(115200);

  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output6, OUTPUT);

  Serial.print("Pins set as output");

  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);
  digitalWrite(output5, LOW);
  digitalWrite(output6, LOW);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop()
{
  WiFiClient client = server.available();

  if (client)
  {
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected() && currentTime - previousTime <= timeoutTime)
    {
      currentTime = millis();

      if (client.available())
      {
        char c = client.read();
        Serial.write(c);
        header += c;

        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Handle button presses
            if (header.indexOf("GET /1/on") >= 0)
            {
              Serial.println("GPIO 1 on");
              output1State = "on";
              digitalWrite(output1, HIGH);
            }
            else if (header.indexOf("GET /1/off") >= 0)
            {
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(output1, LOW);
            }
            else if (header.indexOf("GET /2/on") >= 0)
            {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(output2, HIGH);
            }
            else if (header.indexOf("GET /2/off") >= 0)
            {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            }
            else if (header.indexOf("GET /3/on") >= 0)
            {
              Serial.println("GPIO 3 on");
              output3State = "on";
              digitalWrite(output3, HIGH);
            }
            else if (header.indexOf("GET /3/off") >= 0)
            {
              Serial.println("GPIO 3 off");
              output3State = "off";
              digitalWrite(output3, LOW);
            }
            else if (header.indexOf("GET /4/on") >= 0)
            {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            }
            else if (header.indexOf("GET /4/off") >= 0)
            {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            }
            else if (header.indexOf("GET /5/on") >= 0)
            {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
            }
            else if (header.indexOf("GET /5/off") >= 0)
            {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            }
            else if (header.indexOf("GET /6/on") >= 0)
            {
              Serial.println("GPIO 6 on");
              output6State = "on";
              digitalWrite(output6, HIGH);
            }
            else if (header.indexOf("GET /6/off") >= 0)
            {
              Serial.println("GPIO 6 off");
              output6State = "off";
              digitalWrite(output6, LOW);
            }

            client.println(processor(String(MAIN_page)));
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
      }
    }

    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}