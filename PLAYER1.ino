const int IN1 = 2;//define pin 2 for A1A
const int IN2 = 3;//define pin 3 for A1B
int inputPin = 9; // signal receiver pin ECHO to D9
int outputPin = 8; // signal transmitter pin TRIG to D8
int myspeed = 0;
int olddistance = 0;
int steps = 0;
int buzzer = 12;
unsigned long current_millis;
unsigned long prev_millis;



void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  olddistance = pulseIn(inputPin, HIGH);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(buzzer,OUTPUT);// buzzer pin  mode for buzzer
  //delay(500);

}
void loop()
{
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);
  distance = distance / 58;// calculating the ultrasonic sensor
  int diff = abs(distance - olddistance);



  current_millis = millis();
  if (millis() - prev_millis >= 2000) {
    prev_millis = millis();
    myspeed = 100 + steps * 10;
    if (myspeed > 255) myspeed = 255;
    if (myspeed < 100) myspeed = 100;

    steps = 0;
  }
  if (diff > 70) {
    //Serial.println(diff);
    olddistance = distance;
    steps++;
  }
  if (steps > 1){
    digitalWrite(buzzer,HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
    delay(50);
  }
  //delay(10);
  Serial.print("Speed=");
  Serial.print(myspeed);
  Serial.println(" ");
  Serial.println(steps);
  digitalWrite(IN1, HIGH);
  digitalWrite(4, LOW);
  analogWrite(IN2, myspeed);
  //delay(100);
  // Serial.print("Speed=");
  //Serial.print(myspeed);
  // Serial.println(" ");
  //digitalWrite(IN1, HIGH);
  //digitalWrite(4, LOW);
  //analogWrite(IN2, 240);
  //delay(100);
}
