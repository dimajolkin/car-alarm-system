class Rele {
  private:
     int pin;
  public:
     Rele(int p): pin(p) {}
     void attach() {
        pinMode(pin, OUTPUT); 
     }
     
     void enable() {
        digitalWrite(pin, LOW); 
     }

     void disable() {
        digitalWrite(pin, HIGH);
     }
    
};
