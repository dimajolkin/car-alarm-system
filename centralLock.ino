class CentralLock: public Attach {
  private:
     int plock;
     int plunock;

  public:
     Lock(int pinLock, int pinUnlock): plock(pinLock), plunock(pinUnlock)  {
      
     }

     void attach () {
        pinMode(plock, OUTPUT);
        pinMode(plunock, OUTPUT);
     }

     void lock() {
        digitalWrite(plock, LOW);
        digitalWrite(plunock, HIGH);  
     }

     void unlock () {
        digitalWrite(plock, HIGH);
        digitalWrite(plunock, LOW); 
     }
  
};
