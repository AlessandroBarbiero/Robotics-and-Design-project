#include <Arduino.h>
#include <WiFiConnection.h>
#include <WiFi101.h>
#include <SPI.h>

#define DELTA_PING 5000

WiFiConnection::WiFiConnection(){

}

int WiFiConnection::getPort(){
    return _port;
}

char* WiFiConnection::getHost(){
    return  _host;
}

char* WiFiConnection::getssid(){
    return _ssid;
}

char* WiFiConnection::getPassword(){
    return _password;
}

WiFiClient WiFiConnection::getClient(){
    return _client;
}

void WiFiConnection::setup(){
    _nfc.run();
    _ssid = _nfc.getSSID();
    _password = _nfc.getPassword();
    Serial.print("Connecting to ");
    Serial.println(getssid());

    WiFi.begin(getssid(), getPassword());
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(600);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void WiFiConnection::connect(){
    Serial.print("connecting to ");
    Serial.println(getHost());
    if (!getClient().connect(getHost(), getPort())) {
        Serial.println("connection failed");
        return;
    }
}

void WiFiConnection::ping(WiFiClient client){
    unsigned long currentTime = millis();
    if(!_isPinging){
        _isPinging = true;
        _pingActivationTime = millis();
        client.write('p');
    }
    if(currentTime > _pingActivationTime + DELTA_PING){
        _isPinging = false;
    }
}

void WiFiConnection::setNFC(NFC nfc){
    _nfc = nfc;
}
