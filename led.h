class Led: public Attach {
  private:
     int pin;
  public:
     Led(int p): pin(p) {}

     void attach() {
        pinMode(pin, OUTPUT);
     }

     void start() {
        digitalWrite(pin, HIGH);
     }

     void stop() {
       digitalWrite(pin, LOW);
     }
};

