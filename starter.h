class Starter: public Attach {
  private:
     int pin;
  public:
     Starter(int p): pin(p) {}
     void attach() {
         pinMode(pin, OUTPUT);
     }
     
     void allowed() {
         digitalWrite(pin, HIGH);
     }

     void disabled() {
         digitalWrite(pin, LOW);
      }
};
