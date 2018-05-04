class Starter: public Attach {
  private:
     int pin;
  public:
     Starter(int p): pin(p) {}
     void attach() {}
     void allowed() {}
  
};
