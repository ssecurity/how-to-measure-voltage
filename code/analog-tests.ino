void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float napr_vcc = 0;
  float napr_int = 0;
  // switch to VCC 
  analogReference(DEFAULT);
  delay(50);
  // fake measure
  napr_vcc = analogRead(A0);
  delay(50);
  napr_vcc = analogRead(A0);
  // switch to internal 
  analogReference(INTERNAL);
  delay(50);
  // fake measure
  napr_int = analogRead(A0);
  delay(50);
  napr_int = analogRead(A0);
  Serial.print("VALUES: ");
  Serial.print(napr_vcc);
  Serial.print("(vcc) / ");
  Serial.print(napr_int);
  Serial.println("(int)");
  // calc power voltage
  float fact_voltage = 1.06 * napr_int / 1023;
  float real_voltage = fact_voltage * 1023 / napr_vcc; 
  Serial.print("Vfact: ");
  Serial.print(fact_voltage);
  Serial.print("V\n");
  Serial.print("Vvcc: ");
  Serial.print(real_voltage);
  Serial.print("V\n\n");

  delay(1000);
}
