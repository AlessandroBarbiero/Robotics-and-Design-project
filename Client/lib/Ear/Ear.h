#ifndef Ear_h
    #define Ear_h
    #include "Arduino.h"
    #include <WiFi101.h>
    #include <Servo.h>
    class Ear {
        public:
            Ear();
            Ear(int pin, bool isRight);
            void connect();
            void disconnect();
            void caress();
            void hug();
            void shake();
            void read();
            void idle();
            void moveUp(int delta);
            void moveDown(int delta);
            void moveDownUpDown(int start,int stop, int time);
            void moveUpDownUp(int start, int stop, int time);
        private:
            WiFiClient _client;
            int _pin;
            Servo _servo;
            int _angle = 0;
            bool _isRight;
            bool _isGoingUp;
            unsigned long _hugActivationTime = 0;
            unsigned long _hugDuration = 10000;
            unsigned long _caressActivationTime = 0;
            unsigned long _caressDuration = 10000;
            bool _isHugging = false;
            bool _isCaressing = false;

    };
    
#endif