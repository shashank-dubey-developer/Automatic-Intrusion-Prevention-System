//For Transmitter Circuit (Master)

#include<NewPing.h>
#include<Servo.h>
int op1=2;
int op2=3;

void setup() {
    
    pinMode(op1,OUTPUT);
    pinMode(op2,OUTPUT);
    digitalWrite(op1,LOW);
    digitalWrite(op2,LOW);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    Serial.begin(9600);
}

unsigned char x;

void loop() {

    if(Serial.available() > 0)
    {
        x=Serial.read();
        if(x == '1'){
            Serial.println('1'); digitalWrite(op1,HIGH); delay(1000);
            digitalWrite(op1,LOW); delay(500);
            }
        if(x == '2'){
            Serial.println('2'); digitalWrite(op2,HIGH); delay(1000);
        digitalWrite(op2,LOW); delay(500);
        }
    }

    if(digitalRead(A0) == LOW)
    {
        Serial.println('4');digitalWrite(op1,HIGH); delay(1000);
        digitalWrite(op1,LOW); delay(500);
    }

    if(digitalRead(A1) == LOW)
    {
        Serial.println('5'); digitalWrite(op2,HIGH); delay(1000);
        digitalWrite(op2,LOW); delay(500);
    }
}

