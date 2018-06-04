
#define TIME_FOR_NEXT_COMMAND 2

class Control: public Attach {
  public:
     virtual bool pressLock() = 0;
     virtual bool pressUnlock() = 0;
     virtual bool pressTrunk() = 0;
     virtual bool pressSearch() = 0;
     virtual bool isPress() = 0;
};

class SerialControl: public Control {
  private:
     int p1;
     int p2;
     int p3;
     int p4;

     int c = 0;
     int _tick = 0;

     void serialFlush(){
        while(Serial.available() > 0) {
              char t = Serial.read();
        }
     } 

  public:
     SerialControl() {}

     void attach() {
        
     }

     void tick() {
        _tick++;
     }
      
     bool isPress() {
        if (_tick > TIME_FOR_NEXT_COMMAND && Serial.available() > 0) {
            c = Serial.read();
        } else {
            c = 0;
        }
        
        serialFlush();
        if (c == 'a' || c == 'b' || c =='c' || c == 'd') {
           _tick = 0;
          
        }

        return c > 0;
     }
     int read() {return c;}

     bool pressLock() {
        return c == 'a';
     }
     
     bool pressUnlock() {
        return c == 'b';
     }
     
     // открытие багажника
     bool pressTrunk() {
        return c == 'c';
     }

      // открытие багажника
     bool pressSearch() {
        return c == 'd'; 
     }
 };

 class KeyWirelessRemote433MHZControl: public Control {
  private:
     int p1;
     int p2;
     int p3;
     int p4;
     
  public:
     KeyWirelessRemote433MHZControl(int p1, int p2, int p3, int p4): p1(p1), p2(p2), p3(p3), p4(p4) {}

     void attach() {
        pinMode(p1, INPUT);
        pinMode(p2, INPUT);
        pinMode(p3, INPUT);
        pinMode(p4, INPUT);
     }

     bool pressLock() {
        return digitalRead(p1) == HIGH;
     }
     
     bool pressUnlock() {
        return digitalRead(p2) == HIGH;
     }
     
     // открытие багажника
     bool pressTrunk() {
        return digitalRead(p3) == HIGH;
     }

      // открытие багажника
     bool pressSearch() {
        return digitalRead(p4) == HIGH;
     }
 };
