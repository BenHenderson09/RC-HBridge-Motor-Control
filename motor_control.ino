#include <XBOXRECV.h>

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXRECV Xbox(&Usb);


int m2_f = 7;
int m2_b = 6;
int m1_b = 5;
int m1_f = 4;
void setup() {
  pinMode(m2_f, OUTPUT);
  pinMode(m2_b, OUTPUT);
  pinMode(m1_b, OUTPUT);
  pinMode(m1_f, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
 

//Controller----------
  #if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXbox Wireless Receiver Library Started"));
  //-------------------
}
void loop() {

 Usb.Task();
  if (Xbox.XboxReceiverConnected) {
    for (uint8_t i = 0; i < 4; i++) {
      if (Xbox.Xbox360Connected[i]) {

          
           Serial.print("L2: ");
          Serial.print(Xbox.getButtonPress(L2, i));
          Serial.print("\tR2: ");
          Serial.println(Xbox.getButtonPress(R2, i));
          Xbox.setRumbleOn(Xbox.getButtonPress(L2, i), Xbox.getButtonPress(R2, i), i);

         if (Xbox.getButtonPress(R2, i) > 50 && Xbox.getButtonPress(L2, i) < 50){
          //right
          digitalWrite(m1_f, HIGH);
          delay(50);
          digitalWrite(m1_f, LOW);
          
          }else if (Xbox.getButtonPress(R2, i) < 50 && Xbox.getButtonPress(L2, i) > 50){
            //left
          digitalWrite(m2_f, HIGH);
          delay(50);
          digitalWrite(m2_f, LOW);
            }

          if (Xbox.getButtonPress(R2, i) > 50 && Xbox.getButtonPress(L2, i) > 50){
            //forward
            digitalWrite(m2_f, HIGH);
            delay(25);
            digitalWrite(m1_f, HIGH);
            delay(25);
            digitalWrite(m2_f, LOW);
            digitalWrite(m1_f, LOW);
            }

      }

    }
  }
}

void stop(){
  digitalWrite(m1_f, LOW);
  digitalWrite(m1_b, LOW);
  digitalWrite(m2_b, LOW);
  digitalWrite(m2_f, LOW);
}
void forward(){
digitalWrite(m2_f, HIGH);
delay(100);
digitalWrite(m1_f, HIGH);
delay(100);
}
void reverse(){
digitalWrite(m2_b, HIGH);
delay(100);
digitalWrite(m1_b, HIGH);
delay(100);
}
void rightTurn(){
digitalWrite(m1_f, HIGH);
delay(50);
digitalWrite(m1_f, LOW);
}
void leftTurn(){
digitalWrite(m2_f, HIGH);
delay(50);
digitalWrite(m2_f, LOW);
}

//this will cause left motor to turn. m1_2 backwards, m1_1 forwards
//digitalWrite(m1_1, HIGH);
//digitalWrite(m1_2, HIGH);
//this will cause right motor to turn. m2_4 forward, m2_3 backwards
//digitalWrite(m2_3, HIGH);
//digitalWrite(m2_4, HIGH);
