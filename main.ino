
#include "attach.h"
#include "control.h"
#include "led.h"
#include "rele.h"

// auto device
#include "starter.h"
#include "turnSignal.h" //  реле с поворотниками
#include "centralLock.h"

#define DEBUG 0 


#define PIN_TRUNK 5  //пин багажника
#define PIN_TURN_SIGNAL 12 // поворотники
#define PIN_LOCK 11 // запирание
#define PIN_UNLOCK 9 // отпирание

#define PIN_ANTENNA_LED 13 // диод антенны
#define PIN_IS_ENABLED 2 // включено ли зажигание
#define PIN_SOUNT 3 // сирена
#define PIN_STARTER 4 //разрешить включать стартер


CentralLock lock(PIN_LOCK, PIN_UNLOCK);
//Starter starter(RELE_3);
TurnSignal turnSignal(PIN_TURN_SIGNAL);

Led led(PIN_ANTENNA_LED);

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
      turnSignal.enabled();
      delay(100);
      turnSignal.disabled();

       Serial.println("press search");  
    }
  }
}
 
