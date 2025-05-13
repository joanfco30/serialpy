
#define red 10
#define green 9
#define blue 8
#define DT 2000
unsigned long tini = 0;
unsigned long tsta = 0;
unsigned long tact = 0;
bool end_char = false;

char channel = ' ';
int colorChannel = 0;
//Simular la señal de dos sensores

float temp = 24.5;

float humidity = 56;

String data_string;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);


  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);


  tini = millis();
  randomSeed(millis());
}

void loop() {
  // put your main code here, to run repeatedly:
  // int val_blue = random(0, 255);
  //int val_green = random(0, 255);
  //int val_red = random(0, 255);


  tact = millis();
  tsta = tact - tini;
  temp = random(19.00, 30.00);
  humidity = random(60.00, 80.00);




  if (tsta >= DT) {
    if (channel == 'r') {
      analogWrite(red, colorChannel);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      
    }
    if (channel == 'g') {
      analogWrite(green, colorChannel);
      analogWrite(red, 0);
      analogWrite(blue, 0);
    }
    if (channel == 'b') {
      analogWrite(blue, colorChannel);
      analogWrite(green, 0);
      analogWrite(red, 0);
    }


    //analogWrite(green, val_green);
    //analogWrite(blue, val_blue);
    //analogWrite(red, val_red);
    Serial3.println('t' + String(temp));
    Serial3.println('h' + String(humidity));


    tini = millis();
  }

  while (Serial3.available()) {

    char data = (char)Serial3.read();
    if (isdigit(data)) {
      data_string += data;
    }


    if (data == 'r' || data == 'b' || data == 'g') {
      channel = data;
      Serial.print(channel);
      Serial.print(" ");

      Serial.println(data_string);
      colorChannel = data_string.toInt();
      data_string = "";
    }
  }
  
}
