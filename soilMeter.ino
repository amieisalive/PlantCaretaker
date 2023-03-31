//největší vlhkost je
//vše nad 750 je suché
//perfektní vlhkost je mezi 500 a 750

const int Power = 7;
const int Pin = A0;
const int Wet = 500;
const int Dry = 750;
const int Motor = 6;

int readSensor() {
  digitalWrite(Power, HIGH);
  delay(10);
  int val = analogRead(Pin);
  digitalWrite(Power, LOW);
  return val;
}
void setup() {
  pinMode(Power, OUTPUT);
  pinMode(Motor, OUTPUT);
  digitalWrite(Power, LOW);
  Serial.begin(9600);
}

void loop() {
  int moisture = readSensor();
  Serial.print("analog output");
  Serial.println(moisture);
  delay(2500);

  if (moisture < Wet) {
    Serial.println("moc vlhké lol");
  }
  else if (Dry > moisture && moisture > Wet) {
    Serial.println("perfektní");
  }
  else if (moisture > Dry) {
    Serial.println("trochu sucho");
    
    for (int i = 200; i <= 255; i = i+1){
      Serial.println("motor1");
      analogWrite(Motor, i);
      delay(10);
    }
    for (int i = 255; i!= 200; i = i-1){
      Serial.println("motor2");
      analogWrite(Motor, i);
      delay(10);
    }
  }
}
