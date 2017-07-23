int switchState = LOW;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else { // button pressed
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(250);

    for ( int i=1; i<10; i++ ) {
      digitalWrite(4, HIGH);
      if ( i % 2 ) {
        digitalWrite(5, LOW);
      } else {
        digitalWrite(5, HIGH);
      }
      delay(250);    
    }
  }
}
