#include <WiFi.h>
#include "webpage.h" // <-- Include your webpage

const char *ssid = "welim";
const char *password = "wilywily";

WiFiServer server(80);

// Define output pins
const int out_circ_grande_1 = 4;
const int out_circ_grande_2 = 5;
const int out_circ_grande_3 = 12;
const int out_circ_grande_4 = 13;
const int out_circ_grande_5 = 14;

const int out_circ_med_1 = 15;
const int out_circ_med_2 = 16;
const int out_circ_med_3 = 17;
const int out_circ_med_4 = 18;

const int out_circ_peq_1 = 19;
const int out_circ_peq_2 = 20;

const int out_boton_heli = 21;
const int out_boton_sec1 = 22;
const int out_boton_sec2 = 23;
const int out_boton_sec3 = 24;
const int out_boton_sec4 = 25;
const int out_boton_sec5 = 26;

// Define output states
const String COLOR_CIRC_APAGADO = "#f5fa0bA6";
const String COLOR_CIRC_ENCENDIDO = "#f5fa0b";
const String CLASE_BOTON_ON = "button_on";
const String CLASE_BOTON_OFF = "button_off";

String color_circ_grande_1 = COLOR_CIRC_APAGADO;
String color_circ_grande_2 = COLOR_CIRC_APAGADO;
String color_circ_grande_3 = COLOR_CIRC_APAGADO;
String color_circ_grande_4 = COLOR_CIRC_APAGADO;
String color_circ_grande_5 = COLOR_CIRC_APAGADO;

String color_circ_med_1 = COLOR_CIRC_APAGADO;
String color_circ_med_2 = COLOR_CIRC_APAGADO;
String color_circ_med_3 = COLOR_CIRC_APAGADO;
String color_circ_med_4 = COLOR_CIRC_APAGADO;

String color_circ_peq_1 = COLOR_CIRC_APAGADO;
String color_circ_peq_2 = COLOR_CIRC_APAGADO;

String clase_boton_heli = CLASE_BOTON_OFF;
String clase_boton_sec1 = CLASE_BOTON_OFF;
String clase_boton_sec2 = CLASE_BOTON_OFF;
String clase_boton_sec3 = CLASE_BOTON_OFF;
String clase_boton_sec4 = CLASE_BOTON_OFF;
String clase_boton_sec5 = CLASE_BOTON_OFF;

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

String processor(String page)
{
  // Defining colors
  page.replace("%color_circ_grande_1%", color_circ_grande_1);
  page.replace("%color_circ_grande_2%", color_circ_grande_2);
  page.replace("%color_circ_grande_3%", color_circ_grande_3);
  page.replace("%color_circ_grande_4%", color_circ_grande_4);
  page.replace("%color_circ_grande_5%", color_circ_grande_5);

  page.replace("%color_circ_med_1%", color_circ_med_1);
  page.replace("%color_circ_med_2%", color_circ_med_2);
  page.replace("%color_circ_med_3%", color_circ_med_3);
  page.replace("%color_circ_med_4%", color_circ_med_4);

  page.replace("%color_circ_peq_1%", color_circ_peq_1);
  page.replace("%color_circ_peq_2%", color_circ_peq_2);

  // Defining classes
  page.replace("%clase_boton_heli%", clase_boton_heli);
  page.replace("%clase_boton_sec1%", clase_boton_sec1);
  page.replace("%clase_boton_sec2%", clase_boton_sec2);
  page.replace("%clase_boton_sec3%", clase_boton_sec3);
  page.replace("%clase_boton_sec4%", clase_boton_sec4);
  page.replace("%clase_boton_sec5%", clase_boton_sec5);

  // Defining urls
  page.replace("url_circ_grande_1", color_circ_grande_1 == COLOR_CIRC_APAGADO ? "/circ_grande_1/on" : "/circ_grande_1/off");
  page.replace("url_circ_grande_2", color_circ_grande_2 == COLOR_CIRC_APAGADO ? "/circ_grande_2/on" : "/circ_grande_2/off");
  page.replace("url_circ_grande_3", color_circ_grande_3 == COLOR_CIRC_APAGADO ? "/circ_grande_3/on" : "/circ_grande_3/off");
  page.replace("url_circ_grande_4", color_circ_grande_4 == COLOR_CIRC_APAGADO ? "/circ_grande_4/on" : "/circ_grande_4/off");
  page.replace("url_circ_grande_5", color_circ_grande_5 == COLOR_CIRC_APAGADO ? "/circ_grande_5/on" : "/circ_grande_5/off");

  page.replace("url_circ_med_1", color_circ_med_1 == COLOR_CIRC_APAGADO ? "/circ_med_1/on" : "/circ_med_1/off");
  page.replace("url_circ_med_2", color_circ_med_2 == COLOR_CIRC_APAGADO ? "/circ_med_2/on" : "/circ_med_2/off");
  page.replace("url_circ_med_3", color_circ_med_3 == COLOR_CIRC_APAGADO ? "/circ_med_3/on" : "/circ_med_3/off");
  page.replace("url_circ_med_4", color_circ_med_4 == COLOR_CIRC_APAGADO ? "/circ_med_4/on" : "/circ_med_4/off");

  page.replace("url_circ_peq_1", color_circ_peq_1 == COLOR_CIRC_APAGADO ? "/circ_peq_1/on" : "/circ_peq_1/off");
  page.replace("url_circ_peq_2", color_circ_peq_2 == COLOR_CIRC_APAGADO ? "/circ_peq_2/on" : "/circ_peq_2/off");

  page.replace("%url_boton_heli%", clase_boton_heli == CLASE_BOTON_OFF ? "/boton_heli/on" : "/boton_heli/off");
  page.replace("%url_boton_sec1%", clase_boton_sec1 == CLASE_BOTON_OFF ? "/boton_sec1/on" : "/boton_sec1/off");
  page.replace("%url_boton_sec2%", clase_boton_sec2 == CLASE_BOTON_OFF ? "/boton_se2c/on" : "/boton_sec2/off");
  page.replace("%url_boton_sec3%", clase_boton_sec3 == CLASE_BOTON_OFF ? "/boton_sec3/on" : "/boton_sec3/off");
  page.replace("%url_boton_sec4%", clase_boton_sec4 == CLASE_BOTON_OFF ? "/boton_sec4/on" : "/boton_sec4/off");
  page.replace("%url_boton_sec5%", clase_boton_sec5 == CLASE_BOTON_OFF ? "/boton_sec5/on" : "/boton_sec5/off");

  return page;
}

void setup()
{
  Serial.begin(115200);

  pinMode(out_circ_grande_1, OUTPUT);
  pinMode(out_circ_grande_2, OUTPUT);
  pinMode(out_circ_grande_3, OUTPUT);
  pinMode(out_circ_grande_4, OUTPUT);
  pinMode(out_circ_grande_5, OUTPUT);

  pinMode(out_circ_med_1, OUTPUT);
  pinMode(out_circ_med_2, OUTPUT);
  pinMode(out_circ_med_3, OUTPUT);
  pinMode(out_circ_med_4, OUTPUT);

  pinMode(out_circ_peq_1, OUTPUT);
  pinMode(out_circ_peq_2, OUTPUT);

  pinMode(out_boton_heli, OUTPUT);
  pinMode(out_boton_sec1, OUTPUT);
  pinMode(out_boton_sec2, OUTPUT);
  pinMode(out_boton_sec3, OUTPUT);
  pinMode(out_boton_sec4, OUTPUT);
  pinMode(out_boton_sec5, OUTPUT);

  Serial.print("Pins set as output");

  digitalWrite(out_circ_grande_1, LOW);
  digitalWrite(out_circ_grande_2, LOW);
  digitalWrite(out_circ_grande_3, LOW);
  digitalWrite(out_circ_grande_4, LOW);
  digitalWrite(out_circ_grande_5, LOW);

  digitalWrite(out_circ_med_1, LOW);
  digitalWrite(out_circ_med_2, LOW);
  digitalWrite(out_circ_med_3, LOW);
  digitalWrite(out_circ_med_4, LOW);

  digitalWrite(out_circ_peq_1, LOW);
  digitalWrite(out_circ_peq_2, LOW);

  digitalWrite(out_boton_heli, LOW);
  digitalWrite(out_boton_sec1, LOW);
  digitalWrite(out_boton_sec2, LOW);
  digitalWrite(out_boton_sec3, LOW);
  digitalWrite(out_boton_sec4, LOW);
  digitalWrite(out_boton_sec5, LOW);

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
            if (header.indexOf("GET /circ_grande_1/on") >= 0)
            {
              Serial.println("url circ_grande_1 on");
              color_circ_grande_1 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_grande_1, HIGH);
            }
            else if (header.indexOf("GET /circ_grande_1/off") >= 0)
            {
              Serial.println("url circ_grande_1 off");
              color_circ_grande_1 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_grande_1, LOW);
            }
            else if (header.indexOf("GET /circ_grande_2/on") >= 0)
            {
              Serial.println("url circ_grande_2 on");
              color_circ_grande_2 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_grande_2, HIGH);
            }
            else if (header.indexOf("GET /circ_grande_2/off") >= 0)
            {
              Serial.println("url circ_grande_2 off");
              color_circ_grande_2 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_grande_2, LOW);
            }
            else if (header.indexOf("GET /circ_grande_3/on") >= 0)
            {
              Serial.println("url circ_grande_3 on");
              color_circ_grande_3 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_grande_3, HIGH);
            }
            else if (header.indexOf("GET /circ_grande_3/off") >= 0)
            {
              Serial.println("url circ_grande_3 off");
              color_circ_grande_3 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_grande_3, LOW);
            }
            else if (header.indexOf("GET /circ_grande_4/on") >= 0)
            {
              Serial.println("url circ_grande_4 on");
              color_circ_grande_4 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_grande_4, HIGH);
            }
            else if (header.indexOf("GET /circ_grande_4/off") >= 0)
            {
              Serial.println("url circ_grande_4 off");
              color_circ_grande_4 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_grande_4, LOW);
            }
            else if (header.indexOf("GET /circ_grande_5/on") >= 0)
            {
              Serial.println("url circ_grande_5 on");
              color_circ_grande_5 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_grande_5, HIGH);
            }
            else if (header.indexOf("GET /circ_grande_5/off") >= 0)
            {
              Serial.println("url circ_grande_5 off");
              color_circ_grande_5 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_grande_5, LOW);
            }
            if (header.indexOf("GET /circ_med_1/on") >= 0)
            {
              Serial.println("url circ_med_1 on");
              color_circ_med_1 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_med_1, HIGH);
            }
            else if (header.indexOf("GET /circ_med_1/off") >= 0)
            {
              Serial.println("url circ_med_1 off");
              color_circ_med_1 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_med_1, LOW);
            }
            else if (header.indexOf("GET /circ_med_2/on") >= 0)
            {
              Serial.println("url circ_med_2 on");
              color_circ_med_2 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_med_2, HIGH);
            }
            else if (header.indexOf("GET /circ_med_2/off") >= 0)
            {
              Serial.println("url circ_med_2 off");
              color_circ_med_2 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_med_2, LOW);
            }
            else if (header.indexOf("GET /circ_med_3/on") >= 0)
            {
              Serial.println("url circ_med_3 on");
              color_circ_med_3 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_med_3, HIGH);
            }
            else if (header.indexOf("GET /circ_med_3/off") >= 0)
            {
              Serial.println("url circ_med_3 off");
              color_circ_med_3 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_med_3, LOW);
            }
            else if (header.indexOf("GET /circ_med_4/on") >= 0)
            {
              Serial.println("url circ_med_4 on");
              color_circ_med_4 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_med_4, HIGH);
            }
            else if (header.indexOf("GET /circ_med_4/off") >= 0)
            {
              Serial.println("url circ_med_4 off");
              color_circ_med_4 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_med_4, LOW);
            }
            if (header.indexOf("GET /circ_peq_1/on") >= 0)
            {
              Serial.println("url circ_peq_1 on");
              color_circ_peq_1 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_peq_1, HIGH);
            }
            else if (header.indexOf("GET /circ_peq_1/off") >= 0)
            {
              Serial.println("url circ_peq_1 off");
              color_circ_peq_1 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_peq_1, LOW);
            }
            else if (header.indexOf("GET /circ_peq_2/on") >= 0)
            {
              Serial.println("url circ_peq_2 on");
              color_circ_peq_2 = COLOR_CIRC_ENCENDIDO;
              digitalWrite(out_circ_peq_2, HIGH);
            }
            else if (header.indexOf("GET /circ_peq_2/off") >= 0)
            {
              Serial.println("url circ_peq_2 off");
              color_circ_peq_2 = COLOR_CIRC_APAGADO;
              digitalWrite(out_circ_peq_2, LOW);
            }
            else if (header.indexOf("GET /boton_heli/on") >= 0)
            {
              Serial.println("url boton_heli on");
              clase_boton_heli = CLASE_BOTON_ON;
              digitalWrite(out_boton_heli, HIGH);
            }
            else if (header.indexOf("GET /boton_heli/off") >= 0)
            {
              Serial.println("url boton_heli off");
              clase_boton_heli = CLASE_BOTON_OFF;
              digitalWrite(out_boton_heli, LOW);
            }
            else if (header.indexOf("GET /boton_sec1/on") >= 0)
            {
              Serial.println("url boton_sec1 on");
              clase_boton_sec1 = CLASE_BOTON_ON;
              digitalWrite(out_boton_sec1, HIGH);
            }
            else if (header.indexOf("GET /boton_sec1/off") >= 0)
            {
              Serial.println("url boton_sec1 off");
              clase_boton_sec1 = CLASE_BOTON_OFF;
              digitalWrite(out_boton_sec1, LOW);
            }
            else if (header.indexOf("GET /boton_sec2/on") >= 0)
            {
              Serial.println("url boton_sec2 on");
              clase_boton_sec2 = CLASE_BOTON_ON;
              digitalWrite(out_boton_sec2, HIGH);
            }
            else if (header.indexOf("GET /boton_sec2/off") >= 0)
            {
              Serial.println("url boton_sec2 off");
              clase_boton_sec2 = CLASE_BOTON_OFF;
              digitalWrite(out_boton_sec2, LOW);
            }
            else if (header.indexOf("GET /boton_sec3/on") >= 0)
            {
              Serial.println("url boton_sec3 on");
              clase_boton_sec3 = CLASE_BOTON_ON;
              digitalWrite(out_boton_sec3, HIGH);
            }
            else if (header.indexOf("GET /boton_sec3/off") >= 0)
            {
              Serial.println("url boton_sec3 off");
              clase_boton_sec3 = CLASE_BOTON_OFF;
              digitalWrite(out_boton_sec3, LOW);
            }
            else if (header.indexOf("GET /boton_sec4/on") >= 0)
            {
              Serial.println("url boton_sec4 on");
              clase_boton_sec4 = CLASE_BOTON_ON;
              digitalWrite(out_boton_sec4, HIGH);
            }
            else if (header.indexOf("GET /boton_sec4/off") >= 0)
            {
              Serial.println("url boton_sec4 off");
              clase_boton_sec4 = CLASE_BOTON_OFF;
              digitalWrite(out_boton_sec4, LOW);
            }
            else if (header.indexOf("GET /boton_sec5/on") >= 0)
            {
              Serial.println("url boton_sec5 on");
              clase_boton_sec5 = CLASE_BOTON_ON;
              digitalWrite(out_boton_sec5, HIGH);
            }
            else if (header.indexOf("GET /boton_sec5/off") >= 0)
            {
              Serial.println("url boton_sec5 off");
              clase_boton_sec5 = CLASE_BOTON_OFF;
              digitalWrite(out_boton_sec5, LOW);
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