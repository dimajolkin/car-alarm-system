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
     
  public:
     SerialControl() {}

     void attach() {
        
     }

     bool isPress() {
        if (Serial.available() > 0) {
            c = Serial.read();
        } else {
            c = 0;
        }

        return c > 0;
     }
     int read() {return c;}

     bool pressLock() {
        return c == '1';
     }
     
     bool pressUnlock() {
        return c == '2';
     }
     
     // открытие багажника
     bool pressTrunk() {
        return c == '3';
     }

      // открытие багажника
     bool pressSearch() {
        return c == '4'; 
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
