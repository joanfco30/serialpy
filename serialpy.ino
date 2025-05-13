


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char val_char = Serial.read();

    Serial3.write(val_char);
  }
    if (Serial3.available()){

    Serial.println(Serial3.readStringUntil('\n'));
    
  }

}
