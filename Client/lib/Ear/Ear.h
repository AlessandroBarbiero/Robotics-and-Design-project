#ifndef Ear_h
    #define Ear_h
    #include "Arduino.h"
    #include <WiFi101.h>
    #include <Servo.h>
    class Ear {
        public:
            Ear(int pin);
            void action();
            void connect();
            void disconnect();
        private:
            WiFiClient _client;
            int _pin;
            Servo _servo;
            int _angle = 0;
    };
    
#endif