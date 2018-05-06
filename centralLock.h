
class CentralLock: public Attach {
  private:
     int plock;
     int plunock;

  public:
     CentralLock(int pinLock, int pinUnlock): plock(pinLock), plunock(pinUnlock)  {
      
     }

     void attach () {
        pinMode(plock, OUTPUT);
        pinMode(plunock, OUTPUT);
     }

     void lock() {
        digitalWrite(plock, HIGH);
        delay(200);
        digitalWrite(plock, LOW);  
     }

     void unlock () {
        digitalWrite(plunock, HIGH);
        delay(200);
        digitalWrite(plunock, LOW); 
     }
};
