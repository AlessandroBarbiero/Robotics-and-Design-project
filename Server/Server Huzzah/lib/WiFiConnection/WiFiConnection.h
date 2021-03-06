#ifndef WiFiConnection_h
    #define WiFiConnection_h
    #include "Arduino.h"
    #include <SPI.h>
    #include <ESP8266WiFi.h>
    #include <Credentials.h>
    class WiFiConnection {
        public:
            WiFiConnection(WiFiServer server);
            int getPort();
            bool searchClient();
            void setup();
            bool isClientConnected();
            bool checkMessage();
            char readMessage();
            void stopClient();
        private:
            void printData();
            int _port;
            IPAddress _ip = *(new IPAddress(192, 168, 43, 179)); 
            IPAddress _gateway = *(new IPAddress(192, 168, 43, 1));
            IPAddress _subnet = *(new IPAddress(255, 255, 255, 0));
            WiFiServer _server = 0;
            WiFiClient _client;
            Credentials _credentials;
    };
    
#endif