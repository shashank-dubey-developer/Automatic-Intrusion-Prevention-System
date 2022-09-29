//For Receiver Circuit (Slave)

#include<NewPing.h>
#include<Servo.h>

NewPing sonar(2,3,200);
Servo servo1;
unsigned int uS,dist;
unsigned int thresh=40;

void setup() {
    Serial.begin(9600);
    pinMode(4,OUTPUT);

    digitalWrite(4,HIGH);
    servo1.attach(6);
    servo1.write(0);
    delay(2000);
    Serial.println("Initialised");
}

unsigned int pir1,pir2;
unsigned int i;

void loop() {

    pir2=digitalRead(A0);
    pir1=digitalRead(A1);

    Serial.print("P1:");
    Serial.print(pir1);
    Serial.print(" P2:");
    Serial.print(pir2);
    uS=sonar.ping();
    dist=uS/US_ROUNDTRIP_CM;
    Serial.print(" dist:");
    Serial.println(dist);

    delay(100);

    if(pir1==1) {
        for(i=0;i<120;i++) {
            servo1.write(i);
            uS=sonar.ping();
            dist=uS/US_ROUNDTRIP_CM;
            if(dist<thresh&dist!=0) {
                Serial.print("Person shot at "); Serial.println(dist);
                digitalWrite(4,LOW); delay(400); digitalWrite(4,HIGH); delay(1000);
                break;
                }
            delay(15);
        }
        servo1.write(0);
        while(pir1==1||pir2==1) {
            pir2=digitalRead(A0);
            pir1=digtialRead(A1);
        }

    }

    if(pir2==1) {
        for(i=60;i<180;i++) {
            servo1.write(i);
            uS=sonar.ping();
            dist=uS/US_ROUNDTRIP_CM;
            if(dist<thresh&dist!=0) {
                Serial.print("Person shot at "); Serial.println(dist);
                digitalWrite(4,LOW); delay(400); digitalWrite(4,HIGH); delay(1000);
                break;
            }
            delay(15);
        }
        servo1.write(0);
        while(pir1==1||pir2==1) {
            pir2=digitalRead(A0);
            pir1=digitalRead(A1);
        }
    }
}