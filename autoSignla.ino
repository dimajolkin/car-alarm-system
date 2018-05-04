
#include "attach.h"
#include "control.h"
#include "led.h"
#include "rele.h"

// auto device
#include "starter.h"
#include "centralLock.h"

#define RELE_1 2
#define RELE_2 3
#define RELE_3 4

#define LED_1 13

#define DEBUG 0 


Lock lock(RELE_1, RELE_2);
Starter starter(RELE_3);
Led led(LED_1);

SerialControl control;

void setup() {
  Serial.begin(9600);

  led.attach();
  control.attach();
  lock.attach(); 
  starter.attach();

  Serial.println("Init .. ");
}

void loop() {
  if (control.isPress()) {
    if (control.pressLock()) {
       Serial.println("press lock");  
    }
    
    if (control.pressUnlock()) {
       Serial.println("press unlock");  
    }
    
    if (control.pressTrunk()) {
       Serial.println("press trunk");  
    }
    
    if (control.pressSearch()) {
       Serial.println("press search");  
    }
  }
}
 
