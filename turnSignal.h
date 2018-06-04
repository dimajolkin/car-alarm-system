
/**
 * Включение поворотников
 */
class TurnSignal: public Attach {
  private:
     int pin;
  public:
     TurnSignal(int p): pin(p) {}
     void attach() {
         pinMode(pin, OUTPUT);
     }
     
     void enabled() {
         digitalWrite(pin, HIGH);
     }

     void disabled() {
         digitalWrite(pin, LOW);
     }

     void open() {
      enabled();
      delay(100);
      disabled();
     }
};
