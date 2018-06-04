
#define D1 2
#define D2 3
#define D3 4
#define D4 5

#define DELAY 400

void setup () {
   Serial.begin(9600);
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
}

void loop() {
     
  if (digitalRead(D1) == HIGH) {
      Serial.write('d');
      delay(DELAY);
  }

  if (digitalRead(D2) == HIGH) {
     Serial.write('c');
      delay(DELAY);
  }

  if (digitalRead(D3) == HIGH) {
       Serial.write('b');
      delay(DELAY);
  }
  
  if (digitalRead(D4) == HIGH) {
       Serial.write('a');
      delay(DELAY);
  }
}
