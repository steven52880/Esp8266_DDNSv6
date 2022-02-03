#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <AddrList.h>
#include "dynv6.cpp"

WiFiClient client;

const char *ssid = "wifi_name";
const char *password = "wifi_password";

const char *token = "dynv6_token";
const char *zone = "dynv6_zonename";


void setup()
{

    Serial.begin(74880);

    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.print(ssid);

    //Waiting for wifi connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        //Timeout restart
        if (millis() / 1000 > 30)
            ESP.restart();
    }
    Serial.println();
    Serial.println("Connected.");
    
    //Waiting for ipv6
    Serial.print("Waiting for ip");
    String ipv4="0.0.0.0",ipv6="fe80::";
    while (ipv6=="fe80::")
    {
        for (auto addr : addrList)
        {
            if (addr.isV6()&&!addr.isLocal())
                ipv6 = addr.toString();
            if (addr.isV4())
                ipv4 = addr.toString();
        }
        Serial.print(".");
        delay(200);
        //Timeout restart
        if (millis() / 1000 > 30)
            ESP.restart();
    }
    Serial.println();
    
    Serial.println("IPv4: " + ipv4);
    Serial.println("IPv6: " + ipv6);

    //update ipv6
    dynv6 ddns(token, zone);
    int status=ddns.update(ipv6);
    Serial.print("return code: ");
    Serial.println(status);

    WiFi.disconnect(true);
}

void loop()
{
    if (millis()/1000>600)
        ESP.restart();
    delay(1000);
}