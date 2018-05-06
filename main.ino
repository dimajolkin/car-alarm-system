
#include "attach.h"
#include "control.h"
#include "led.h"
#include "rele.h"

// auto device
#include "starter.h"
#include "turnSignal.h" //  реле с поворотниками
#include "centralLock.h"

#define RELE_1 2
#define RELE_2 3
#define RELE_3 4

#define LED_1 13

#define DEBUG 0 


CentralLock lock(RELE_2, RELE_1);
//Starter starter(RELE_3);
TurnSignal turnSignal(RELE_3);

Led led(LED_1);

SerialControl control;

void setup() {
  Serial.begin(9600);

  led.attach();
  control.attach();
  lock.attach(); 
  turnSignal.attach();
  //starter.attach();

  Serial.println("Init .. ");
}

void loop() {
  if (control.isPress()) {
    if (control.pressLock()) {
       lock.lock();
       
       Serial.println("press lock");  
    }
    
    if (control.pressUnlock()) {
       lock.unlock();
       Serial.println("press unlock");  
    }
    
    if (control.pressTrunk()) {
       Serial.println("press trunk");  
    }
    
    if (control.pressSearch()) {
      //starter.allowed();
      led.start();
      delay(1000);
      //starter.disabled();
      led.stop();
       Serial.println("press search");  
    }
  }
}
 
