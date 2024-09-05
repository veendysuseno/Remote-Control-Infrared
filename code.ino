/*
    Program Remote Kontrol IR
*/

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 8;
const int bluePin = 9;
const int orangePin = 10;
const int yellowPin = 11;

void setup() {
    irrecv.enableIRIn();
    irrecv.blink13(true);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(orangePin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {   //Pencarian Kode IR
    /*Kode Perintah Remote*/
    switch (results.value) {
      case 0xFF30CF: //Keypad button "1"
        digitalWrite(redPin, HIGH);
        delay(2000);
        digitalWrite(redPin, LOW);
    }
    switch (results.value) {
      case 0xFF18E7: //Keypad button "2"
        digitalWrite(bluePin, HIGH);
        delay(2000);
        digitalWrite(bluePin, LOW);
    }
    switch (results.value) {
      case 0xFF7A85: //Keypad button "3"
        digitalWrite(orangePin, HIGH);
        delay(2000);
        digitalWrite(orangePin, LOW);
    }
    switch (results.value) {
      case 0xFF10EF: //Keypad button "4"
        digitalWrite(yellowPin, HIGH);
        delay(2000);
        digitalWrite(yellowPin, LOW);
    }

    irrecv.resume();
}
}
