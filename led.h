class Led: public Attach {
  private:
     int pin;
     int status = 0;
  public:
     Led(int p): pin(p) {}

     void attach() {
        pinMode(pin, OUTPUT);
        status = 0;
     }

     void start() {
        status = 1;
        digitalWrite(pin, HIGH);
     }

     void stop() {
       status = 0;
       digitalWrite(pin, LOW);
     }

     void next() {
        if (status == 0) {
             start();
        } else {
             stop();
        }
     }

     void ping() {
        next();
        next();
     }
};

