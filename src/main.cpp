#include <Arduino.h>
#include <Keyboard.h>
#if defined (ARDUINO_RASPBERRY_PI_PICO_W)
  #include <KeyboardBLE.h>
  #define BLE_DEVICE_NAME "PicoW STREAMDECK"
#endif  

#define buttonPin1 9
#define buttonPin2 4
#define buttonPin3 16
#define buttonPin4 21

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  #if defined (ARDUINO_RASPBERRY_PI_PICO_W)
    KeyboardBLE.begin(BLE_DEVICE_NAME);
  #else
    Keyboard.begin(KeyboardLayout_es_ES);
  #endif

}

void loop() {
  #if defined (ARDUINO_RASPBERRY_PI_PICO_W)
    if(!digitalRead(buttonPin1)){
      KeyboardBLE.write(KEY_F13);
      delay(10);
    }
    if(!digitalRead(buttonPin2)){
      KeyboardBLE.write(KEY_F14);
      delay(10);
    }
    if(!digitalRead(buttonPin3)){
      KeyboardBLE.write(KEY_F15);
      delay(10);
    }
    if(!digitalRead(buttonPin4)){
      KeyboardBLE.write(KEY_F16);
      delay(10);
    }
    delay(25);
  #else
    if(!digitalRead(buttonPin1)){
      Keyboard.write(KEY_F13);
      delay(10);
    }
    if(!digitalRead(buttonPin2)){
      Keyboard.write(KEY_F14);
      delay(10);
    }
    if(!digitalRead(buttonPin3)){
      Keyboard.write(KEY_F15);
      delay(10);
    }
    if(!digitalRead(buttonPin4)){
      Keyboard.write(KEY_F16);
      delay(10);
    }
    delay(25);
  #endif
}
