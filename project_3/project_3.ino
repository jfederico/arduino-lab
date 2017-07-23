const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {

  Serial.print("Sensor value: ");
  int sensorVal = analogRead(sensorPin);
  Serial.print(sensorVal);

  Serial.print(", Volts: ");
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);
  Serial.print("\n");

  if ( temperature < baselineTemp ) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if ( temperature >= baselineTemp+1.5 && temperature < baselineTemp+3.0 ) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if ( temperature >= baselineTemp+3.0 && temperature < baselineTemp+4.5) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if ( temperature >= baselineTemp+4.5 ) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(125);  
}
