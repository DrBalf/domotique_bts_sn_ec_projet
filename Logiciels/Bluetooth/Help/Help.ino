float temperature=21.00;
float humidite=50.00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial1.print("$tem");
Serial1.print(temperature);
Serial1.print("$hum");
Serial1.print(humidite);
delay(3000);
}
